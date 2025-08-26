/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:16:53 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/26 17:15:37 by amweyer          ###   ########.fr       */
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
