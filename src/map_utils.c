/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:51:31 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/08/25 16:38:18 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	get_len(char *str)
// {
// 	int	i;
// 	int len;

// 	i = 0;
// 	len = 0;
// 	while (str[i] && str[i] != '1')
// 		i++;
// 	while (str[i] && str[i] != '\n')
// 	{
// 		len++;
// 		i++;
// 	}
// 	return (len);
// }

int	get_len(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str && *str != '1')
		str++;
	if (!*str)
		return (0);
	while (*str && *str != '\n')
	{
		len++;
		str++;
	}
	return (len);
}

int	get_offset(char *str)
{
	int	offset;

	offset = 0;
	if (!str)
		return (0);
	while (str[offset] && str[offset] != '1')
		offset++;
	return (offset);
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

int	check_valid_input(const char *line, const char *valid)
{
	int	i;

	i = 0;
	if(!line || !valid)
		return(1);
	while (line[i])
	{
		if (ft_strchr(valid, line[i]) == NULL)
			return (1);
		i++;
	}
	return (0);
}