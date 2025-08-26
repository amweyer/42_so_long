/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:11:26 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/26 15:43:17 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game)
{
	game->rows = 0;
	game->cols = 0;
	game->ref = 0;
	game->x_offset = 0;
	game->y_offset = 0;
	game->map = NULL;
}

void	init_axis(t_axis *axis)
{
	axis->x = 0;
	axis->y = 0;
}
