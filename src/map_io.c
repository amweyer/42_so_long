/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:19:31 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/25 16:43:23 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (ft_strncmp(filename + len - 4, ".ber\0", 5) == 0)
		return (0);
	return (1);
}

int	open_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		free_error(fd, NULL, 0, NULL);
	return (fd);
}



int	process_line(char *line, t_game *game, int fd)
{
	int len;
	int offset;

	len = get_len(line);
	offset = get_offset(line);
	if (check_valid_input(line, "01CEP\n \t"))
		free_error(fd, line, 1, "Invalid character in map");

	if (len == 0)
	{
		if(game->ref == 0)
			game->y_offset++;
		return (0);
	}

		
	// Si pas encore de référence -> on la fixe ici
	if (game->ref == 0)
	{
		game->ref = 1;
		game->x_offset = offset;
		game->cols = len;
		return (1);
	}

	if (len != game->cols || offset != game->x_offset)
		free_error(fd, line, 1, "Map is not rectangular");

	game->rows++;
	return (0);
}

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open_map(filename);
	line = get_next_line(fd);

	if (!line)
		free_error(fd, NULL, 1, "Empty file");

	while (line)
	{
		if (process_line(line, game, fd))
			game->rows++; // première ligne valide trouvée

		free(line);
		line = get_next_line(fd);
	}

	if (game->rows == 0)
		free_error(fd, NULL, 1, "No valid map found");

	free_sucess(fd);

	printf("rows: %d\n", game->rows);
	printf("cols: %d\n", game->cols);
	printf("x_off: %d\n", game->x_offset);
	printf("y_off: %d\n", game->y_offset);
}




void	fill_map(char *filename, t_game *game)
{
	int		i;
	int		len;
	char	*line;
	int		fd;

	fd = open_map(filename);
	game->map = malloc((game->rows + 1) * sizeof(char *));
	if (!game->map)
		free_error(fd, NULL, 0, "Creaton of the map");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
		{
			free_tab(game->map);
			free_error(fd, NULL, 1, "Creaton of the map");
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	free_sucess(fd);
}
