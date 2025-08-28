/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:23:34 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/28 15:46:50 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		cleanup(fd, NULL, NULL, NULL);
	return (fd);
}

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
	while (*str && *str != '\n' && *str != ' ')
	{
		len++;
		str++;
	}
	return (len);
}

void	flood_fill_path(char **map, t_axis map_size, int row, int col)
{
	if (row < 0 || col < 0 || row >= map_size.y || col >= map_size.x)
		return ;
	if (map[row][col] == '1' || map[row][col] == 'V' || map[row][col] == 'E')
		return ;
	map[row][col] = 'V';
	flood_fill_path(map, map_size, row - 1, col);
	flood_fill_path(map, map_size, row + 1, col);
	flood_fill_path(map, map_size, row, col - 1);
	flood_fill_path(map, map_size, row, col + 1);
}
