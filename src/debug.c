/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:16:59 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/26 16:45:55 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	show_pos(t_axis pos)
// {
// 	printf("x: %d\t", pos.x);
// 	printf("y: %d\n", pos.y);
// }

void	show_map(t_game *game)
{
	int	i;

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
