/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:52:42 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/27 19:20:11 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		game->dy = 1;
	if (keycode == KEY_S)
		game->dy = -1;
	if (keycode == KEY_A)
		game->dx = -1;
	if (keycode == KEY_D)
		game->dy = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		free_exit(game,"game exited succesfully");
	if (keycode == KEY_W)
		game->dy = 0;
	if (keycode == KEY_S)
		game->dy = 0;
	if (keycode == KEY_A)
		game->dx = 0;
	if (keycode == KEY_D)
		game->dy = 0;
	return (0);
}

void move_up()
{
    printf("moving upppp\n");
}


int	map_update(t_game *game)
{
    int b=0;

	if (game->dy > 0)
		move_up();
	// printf("up\n");
	if (game->dy < 0)
		b++;
	// printf("down\n");
    
	return (0);
}

void	play_game(t_game *game)
{
	// printf("play game\n");
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		free_exit(game, "mlx_init failed");
	game->win_ptr = mlx_new_window(game->mlx_ptr, 64 * game->cols, 64
			* game->rows, "so_long");
	if (!game->win_ptr)
		free_exit(game, "mlx_new_window failed");
	// printf("Before load images\n");
	// printf("cols=%d rows=%d\n", game->cols, game->rows);
	load_images(game);
	// printf("BEDORE RENDER\n");
	render_map(game);
	// printf("ok\n");
	mlx_hook(game->win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_press, game);
	mlx_hook(game->win_ptr, KEY_RELEASE, KEY_RELEASE_MASK, key_release, game);
	mlx_loop_hook(game->mlx_ptr, map_update, game);
	mlx_loop(game->mlx_ptr);
	//     return (0);
	// while(1)
	// 	;
}

void	render_map(t_game *game)
{
	t_axis axis;

	// printf("start map\n");
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

	// printf("finish map\n");
}