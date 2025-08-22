/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:51:26 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/08/22 21:10:03 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	show_map(t_game *game)
{
	int	i;

	if(!game)
		return;

	printf("rows: %d\n", game->rows);
	printf("cols: %d\n", game->cols);
	printf("map:\n");
	i = 0;
	while (i < game->rows)
	{
		printf("%s\n", game->map[i]);
		i++;
	}
}

int	parse(char **av, t_game *game)
{
	char	*filename;

	if (!av || !av[1])
		return (1);
	filename = av[1];
	if (check_format(filename))
	{
		printf("error: incorrect format\n");
		return (1);
	}
	init_map(game);
	read_map(filename, game);
	fill_map(filename, game);
	show_map(game);
	if (check_map(game))
	{
		printf("Error with the map\n");
		return (1);
	}
	printf("Map OK\n");
	printf("---------------\n");
	check_path(game);
	printf("---------------\n");
	return (0);
}

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

void	read_map(char *filename, t_game *game)
{
	int		len;
	int		fd;
	char	*line;

	fd = open_map(filename);
	line = get_next_line(fd);
	if (!line)
		free_error(fd, line, 0, NULL);
	game->cols = get_len(line);
	while (line)
	{
		len = get_len(line);
		if (len != game->cols)
		{
			free_tab(game->map);
			free_error(fd, line, 1, "Map is not rectangular");
		}
		free(line);
		line = get_next_line(fd);
		game->rows++;
	}
	free_sucess(fd);
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
			free_error(fd, NULL, 1, "Creaton of the map");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	free_sucess(fd);
}
