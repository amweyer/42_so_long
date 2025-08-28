/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:12:05 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/28 17:57:31 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "libft.h"
# include <mlx.h>
# include <stdio.h>
// # include <mlx_int.h>

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define ON_DESTROY 17

typedef struct s_game
{
	char	**map;
	int		rows;
	int		cols;
	int		ref;
	int		x_offset;
	int		y_offset;
	int		p_x;
	int		p_y;
	int		nb_collectibles;
	int		count_move;
	int		tile_size;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	void	*img_floor;
	void	*img_wall;

}			t_game;

typedef struct s_axis
{
	int		x;
	int		y;
}			t_axis;

typedef struct s_move
{
	int		up;
	int		down;
	int		right;
	int		left;
}			t_move;

/* init.c */
void		init_game(t_game *game);
void		init_axis(t_axis *axis);
void		init_move(t_move *move);

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
void		free_exit(t_game *game, char *msg);

/* map_utils.c */
int			get_len(char *str);
int			get_offset(char *str);
int			count_caracter(t_game *game, char c);
t_game		*copy_game(t_game *game);
t_axis		find_position(t_game *game, char c);
int			check_valid_input(const char *line, const char *valid);

/* debug.c */
void		show_map(t_game *game);

/* game_init.c */
void		load_images(t_game *game);
void		init_map_variables(t_game *game);

/* game.c */
void		play_game(t_game *game);
int			render_map(t_game *game);
int			map_update(t_game *game);
int			key_release(int keycode, t_game *game);
int			key_press(int keycode, t_game *game);
void		select_tile(char c, t_game *game, t_axis axis);
int			close_window(t_game *game);
/* move.c */
void		do_move(t_game *game, t_move *move);
t_axis		set_new_postion(t_game *game, t_move *move);
void		set_axis(t_axis *axis, int x, int y);

#endif