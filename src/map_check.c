/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:44:46 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/23 14:39:53 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game)
{
	if (check_contours(game))
		free_map_exit_fail(game, "Check the contours");
	if (check_caracters(game))
		free_map_exit_fail(game, "Check the caracters");
	if (check_duplicates(game))
		free_map_exit_fail(game, "Check duplicates or caracter presence");
	if (check_path(game))
		free_map_exit_fail(game, "Check path availability");
	return ;
}

int	check_contours(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->rows)
	{
		y = 0;
		while (y < game->cols)
		{
			if ((x == 0) && (game->map[x][y] != '1'))
				return (1);
			if ((x == game->rows - 1) && (game->map[x][y] != '1'))
				return (1);
			if ((y == 0) && (game->map[x][y] != '1'))
				return (1);
			if ((y == game->cols - 1) && (game->map[x][y] != '1'))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	check_caracters(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->rows)
	{
		y = 0;
		while (y < game->cols)
		{
			if (game->map[x][y] != '0' && game->map[x][y] != '1'
				&& game->map[x][y] != 'C' && game->map[x][y] != 'E'
				&& game->map[x][y] != 'P')
			{
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	check_duplicates(t_game *game)
{
	if (count_caracter(game, 'E') != 1)
		return (1);
	if (count_caracter(game, 'P') != 1)
		return (1);
	if (count_caracter(game, 'C') < 1)
		return (1);
	return (0);
}

int	check_path(t_game *game)
{
	t_game	*game_copy;
	t_axis	start_pos;
	t_axis	map_size;

	start_pos = find_position(game, 'P');
	if (start_pos.x == -1)
		return (1);
	map_size.x = game->cols;
	map_size.y = game->rows;
	game_copy = copy_game(game);
	if (!game_copy)
		return (1);
	flood_fill_path(game_copy->map, map_size, start_pos.x, start_pos.y);
	if (count_caracter(game_copy, 'C') != 0)
		return (free_game(game_copy), 1);
	if (count_caracter(game_copy, 'E') != 0)
		return (free_game(game_copy), 1);
	return (free_game(game_copy), 0);
}

void	flood_fill_path(char **map, t_axis map_size, int row, int col)
{
	if (row < 0 || col < 0 || row >= map_size.y || col >= map_size.x)
		return ;
	if (map[row][col] == '1' || map[row][col] == 'V')
		return ;
	map[row][col] = 'V';
	flood_fill_path(map, map_size, row - 1, col);
	flood_fill_path(map, map_size, row + 1, col);
	flood_fill_path(map, map_size, row, col - 1);
	flood_fill_path(map, map_size, row, col + 1);
}
