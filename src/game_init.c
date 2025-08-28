/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:36:09 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/28 18:09:32 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/carrie_64.xpm", &img_width, &img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/collectible_64.xpm", &img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/door_64.xpm", &img_width, &img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/floor_64.xpm", &img_width, &img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/wall_64.xpm", &img_width, &img_height);
	if (!game->img_player || !game->img_collectible || !game->img_exit
		|| !game->img_floor || !game->img_wall)
		free_exit(game, "image could not be loaded");
}

void	init_map_variables(t_game *game)
{
	t_axis	player;

	player = find_position(game, 'P');
	game->p_x = player.x;
	game->p_y = player.y;
	game->nb_collectibles = count_caracter(game, 'C');
}
