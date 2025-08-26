/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:19:31 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/26 17:52:31 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char *filename)
{
	size_t	len;

	if (!filename)
		return (1);
	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (ft_strncmp(filename + len - 4, ".ber\0", 5) == 0)
		return (0);
	return (1);
}

int	process_line(char *line, t_game *game, int fd)
{
	int	len;
	int	offset;

	len = get_len(line);
	offset = get_offset(line);
	if (check_valid_input(line, "01CEP\n \t"))
		cleanup(fd, game->map, line, "Invalid character in map");
	if (len == 0)
	{
		if (game->ref == 0)
			game->y_offset++;
		return (0);
	}
	if (game->ref == 0)
	{
		game->ref = 1;
		game->x_offset = offset;
		game->cols = len;
		return (1);
	}
	if (len != game->cols || offset != game->x_offset)
		cleanup(fd, game->map, line, "Map is not rectangular");
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
		cleanup(fd, game->map, NULL, "Empty file");
	while (line)
	{
		if (process_line(line, game, fd))
			game->rows++;
		free(line);
		line = get_next_line(fd);
	}
	if (game->rows == 0)
		cleanup(fd, game->map, NULL, "No valid map found");
	cleanup(fd, NULL, NULL, NULL);
}

void	fill_map(char *filename, t_game *game)
{
	int		row;
	int		fd;
	char	*line;

	fd = open_map(filename);
	game->map = malloc((game->rows + 1) * sizeof(char *));
	if (!game->map)
		cleanup(fd, game->map, NULL, "Creation of the map");
	int (i) = 0;
	row = 0;
	line = get_next_line(fd);
	while ((line))
	{
		if (i >= game->y_offset && i < game->rows + game->y_offset)
		{
			if (add_line(row, line, game))
				cleanup(fd, game->map, NULL, "Creation of the map");
			row++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[row] = NULL;
	cleanup(fd, NULL, NULL, NULL);
}

int	add_line(int row, char *line, t_game *game)
{
	int	x;

	x = 0;
	game->map[row] = malloc(game->cols + 1);
	if (!game->map[row])
		return (1);
	while (x < game->cols)
	{
		game->map[row][x] = line[x + game->x_offset];
		x++;
	}
	game->map[row][x] = '\0';
	return (0);
}
