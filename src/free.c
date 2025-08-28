/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:16:53 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/28 16:41:58 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup(int fd, char **map, char *line, const char *msg)
{
	if (line)
		free(line);
	if (map)
		free_tab(map);
	if (fd >= 0)
		close(fd);
	free_gnl();
	if (msg)
	{
		ft_printf("Error\n%s\n", msg);
		exit(EXIT_FAILURE);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_tab(game->map);
	free(game);
}

void	free_exit(t_game *game, char *msg)
{
	if (!game)
		return ;

	if (game->img_player)
		mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx_ptr, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (game->img_floor)
		mlx_destroy_image(game->mlx_ptr, game->img_floor);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->img_player = NULL;
	game->img_collectible = NULL;
	game->img_exit = NULL;
	game->img_floor = NULL;
	if (game->map)
		free_tab(game->map);
	if (msg)
	{
		ft_printf("Error\n%s\n", msg);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
