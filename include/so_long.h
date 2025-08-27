/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:12:05 by amweyer           #+#    #+#             */
/*   Updated: 2025/08/27 18:30:26 by amweyer          ###   ########.fr       */
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
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_PRESS_MASK 1L << 0
# define KEY_RELEASE_MASK 1L << 1

typedef struct s_game
{
	char	**map;
	int		rows;
	int		cols;
	int		ref;
	int		x_offset;
	int		y_offset;
	int		player_x;
	int		player_y;
	int		dx;
	int		dy;
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

/* init.c */
void		init_game(t_game *game);
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

/* game.c */
void		play_game(t_game *game);
void		render_map(t_game *game);
int			map_update(t_game *game);
int			key_release(int keycode, t_game *game);
int			key_press(int keycode, t_game *game);

#endif