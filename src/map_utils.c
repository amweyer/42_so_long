/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:51:31 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/08/23 13:14:40 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	count_caracter(t_game *game, char c)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (x < game->rows)
	{
		y = 0;
		while (y < game->cols)
		{
			if (game->map[x][y] == c)
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

t_game	*copy_game(t_game *game)
{
	int		i;
	t_game	*copy;

	i = 0;
	copy = malloc(sizeof(t_game));
	if (!copy)
		return (NULL);
	copy->cols = game->cols;
	copy->rows = game->rows;
	copy->map = malloc(sizeof(char *) * (game->rows + 1));
	if (!copy->map)
		return (free(copy), NULL);
	while (i < game->rows)
	{
		copy->map[i] = ft_strdup(game->map[i]);
		if (!copy->map[i])
		{
			free_tab(copy->map);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy->map[i] = NULL;
	return (copy);
}

t_axis	find_position(t_game *game, char c)
{
	t_axis pos;

	init_axis(&pos);
	while (pos.x < game->rows)
	{
		pos.y = 0;
		while (pos.y < game->cols)
		{
			if (game->map[pos.x][pos.y] == c)
				return (pos);
			pos.y++;
		}
		pos.x++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}