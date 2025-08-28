/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:52:42 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/28 16:42:14 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_action(int keycode, t_game *game)
{
	t_move	move;

	init_move(&move);
	if (keycode == KEY_ESC)
		free_exit(game, NULL);
	if (keycode == KEY_W)
		move.up = 1;
	if (keycode == KEY_S)
		move.down = 1;
	if (keycode == KEY_A)
		move.left = 1;
	if (keycode == KEY_D)
		move.right = 1;
	do_move(game, &move);
	return (0);
}

void	play_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		free_exit(game, "mlx_init failed");
	game->win_ptr = mlx_new_window(game->mlx_ptr, 64 * game->cols, 64
			* game->rows, "so_long");
	if (!game->win_ptr)
		free_exit(game, "mlx_new_window failed");
	init_map_variables(game);
	load_images(game);
	render_map(game);
	ft_printf("moves: %d\n", game->count_move);
	mlx_key_hook(game->win_ptr, key_action, game);
	mlx_loop_hook(game->mlx_ptr, render_map, game);
	mlx_loop(game->mlx_ptr);
}

int	render_map(t_game *game)
{
	t_axis axis;

	init_axis(&axis);
	while (axis.y < game->rows)
	{
		axis.x = 0;
		while (axis.x < game->cols)
		{
			if (game->map[axis.y][axis.x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_wall, axis.x * game->tile_size, axis.y
					* game->tile_size);
			if (game->map[axis.y][axis.x] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_floor, axis.x * game->tile_size, axis.y
					* game->tile_size);
			if (game->map[axis.y][axis.x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_exit, axis.x * game->tile_size, axis.y
					* game->tile_size);
			if (game->map[axis.y][axis.x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_player, axis.x * game->tile_size, axis.y
					* game->tile_size);
			if (game->map[axis.y][axis.x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_collectible, axis.x * game->tile_size, axis.y
					* game->tile_size);
			axis.x++;
		}
		axis.y++;
	}
	return (0);
}