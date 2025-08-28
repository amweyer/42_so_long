/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:51:26 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/08/28 18:12:30 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse(char **av, t_game *game)
{
	char	*filename;

	if (!av || !av[1])
	{
		ft_printf("Error\nInput : incorrect format\n");
		exit(EXIT_FAILURE);
	}
	filename = av[1];
	if (check_format(filename))
	{
		ft_printf("Error\nInput : incorrect format\n");
		exit(EXIT_FAILURE);
	}
	init_game(game);
	read_map(filename, game);
	fill_map(filename, game);
	check_map(game);
}
