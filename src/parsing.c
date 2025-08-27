/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:51:26 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/08/27 11:40:34 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	show_map(t_game *game)
// {
// 	int	i;

// 	if (!game)
// 		return ;
// 	// printf("rows: %d\n", game->rows);
// 	// printf("cols: %d\n", game->cols);
// 	printf("map:\n");
// 	i = 0;
// 	while (i < game->rows)
// 	{
// 		printf("%s\n", game->map[i]);
// 		i++;
// 	}
// }

void	parse(char **av, t_game *game)
{
	char	*filename;

	if (!av || !av[1])
	{
		printf("Error\nInput : incorrect format\n");
		exit(EXIT_FAILURE);
	}
	filename = av[1];
	if (check_format(filename))
	{
		printf("Error\nInput : incorrect format\n");
		exit(EXIT_FAILURE);
	}
	init_game(game);
	read_map(filename, game);
	fill_map(filename, game);
	check_map(game);
	printf("---------------\n");
	printf("Map OK\n");
	printf("---------------\n");
	// show_map(game);
	// 	printf("---------------\n");
}
