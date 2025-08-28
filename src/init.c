/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:11:26 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/28 16:17:28 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->rows = 0;
	game->cols = 0;
	game->ref = 0;
	game->x_offset = 0;
	game->y_offset = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->count_move = 0;
	game->nb_collectibles = 0;
	game->tile_size = TILE_SIZE;
	game->map = NULL;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->img_player = NULL;
	game->img_collectible = NULL;
	game->img_exit = NULL;
	game->img_floor = NULL;
	game->img_wall = NULL;
}

void	init_axis(t_axis *axis)
{
	axis->x = 0;
	axis->y = 0;
}

void	init_move(t_move *move)
{
	if (!move)
		return ;
	move->up = 0;
	move->down = 0;
	move->right = 0;
	move->left = 0;
}
