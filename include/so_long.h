/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:12:05 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/26 18:09:37 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "libft.h"
# include <stdio.h>

typedef struct s_game
{
	char	**map;
	int		rows;
	int		cols;
	int		ref;
	int		x_offset;
	int		y_offset;
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
void		parse(char **av, t_game *game);
int			check_format(char *filename);
int			process_line(char *line, t_game *game, int fd);
void		read_map(char *filename, t_game *game);
void		fill_map(char *filename, t_game *game);

/* map_io.c */
int			add_line(int row, char *line, t_game *game);

/* map_utils2.c */
int			open_map(char *filename);

/* map_check.c */
void		check_map(t_game *game);
int			check_caracters(t_game *game);
int			check_contours(t_game *game);
int			check_path(t_game *game);
int			check_duplicates(t_game *game);
void		flood_fill_path(char **map, t_axis map_size, int row, int col);

/* free.c */
void		cleanup(int fd, char **map, char *line, const char *msg);
void		free_tab(char **tab);
void		free_game(t_game *game);

/* map_utils.c */
int			get_len(char *str);
int			get_offset(char *str);
int			count_caracter(t_game *game, char c);
t_game		*copy_game(t_game *game);
t_axis		find_position(t_game *game, char c);
int			check_valid_input(const char *line, const char *valid);

/* debug.c */
void		show_map(t_game *game);

#endif