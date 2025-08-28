/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:57:43 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/28 16:14:16 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_move(t_game *game, t_move *move)
{
	t_axis	new_p;

	new_p = set_new_postion(game, move);
	if (game->map[new_p.x][new_p.y] == 'E' && game->nb_collectibles == 0)
		free_exit(game, NULL);
	if (game->map[new_p.x][new_p.y] != '1'
		&& game->map[new_p.x][new_p.y] != 'E')
	{
		if (game->map[new_p.x][new_p.y] == 'C')
			game->nb_collectibles--;
		game->map[game->p_x][game->p_y] = '0';
		game->p_x = new_p.x;
		game->p_y = new_p.y;
		game->map[game->p_x][game->p_y] = 'P';
	}
}

t_axis	set_new_postion(t_game *game, t_move *move)
{
	t_axis	new_p;

	init_axis(&new_p);
	set_axis(&new_p, game->p_x, game->p_y);
	if (move->up)
		new_p.x--;
	if (move->down)
		new_p.x++;
	if (move->left)
		new_p.y--;
	if (move->right)
		new_p.y++;
	return (new_p);
}

void	set_axis(t_axis *axis, int x, int y)
{
	axis->x = x;
	axis->y = y;
}
