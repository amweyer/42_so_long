/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:16:53 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/22 11:49:47 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_error(int fd, char *str, int gnl, char *message)
{
	if (str)
		free(str);
	if (gnl)
		free_gnl();
	if (fd >= 0)
		close(fd);
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	free_sucess(int fd)
{
	free_gnl();
	close(fd);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}