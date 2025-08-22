/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:12:05 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/22 13:50:16 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "libft.h"

typedef struct s_game
{
	char	**map;
	// int		length;
	// int		width;
	int		rows;
	int		cols;
	int		c;
	int		e;
	int		p;

}			t_game;

typedef struct s_axis
{
	int		x;
	int		y;
}			t_axis;

/* init.c */
void		init_map(t_game *game);
void		init_axis(t_axis *axis);

/* parsing.c */
int			parse(char **av, t_game *game);
int			check_format(char *filename);
void		read_map(char *filename, t_game *game);
void		fill_map(char *filename, t_game *game);
int			check_contours(t_game *game, int x, int y);
int			check_map(t_game *game);

/* free.c */
void		free_error(int fd, char *str, int gnl, char *message);
void		free_sucess(int fd);
void		free_tab(char **tab);

/* utils.c */
int			get_len(char *str);

#endif