/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:51:16 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/08/22 11:54:44 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_game	game;

    if(ac != 2)
    {
        ft_printf("Error: Incorrect number of arguments\n");
        return 1;
    }
    parse(av, &game);
    free_tab(game.map);
       
}



// int main(void)
// {
//     void    *mlx;
//     void    *win_backgound;
//     void    *win_player;
//     void    *img;
//     void    *img2;
//     void    *img3;
//     char    *relative_path = "./ghost.xpm";
//     char    *relative_path2 = "./pacdot_food.xpm";
//     char    *relative_path3 = "./portal.xpm";

//     int     img_width;
//     int     img_height;

//     mlx = mlx_init();
//     if (!mlx)
//         return (1);

//     win_backgound = mlx_new_window(mlx, 800, 600, "Test image");
//     win_player = mlx_new_window(mlx, 800, 600, "Test image");
//     if (!win_player)
//         return (1);

//     img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	img2 = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);
// 	img3 = mlx_xpm_file_to_image(mlx, relative_path3, &img_width, &img_height);
//     if (img == NULL)
//     {
//         printf("Impossible de charger l'image !\n");
//         return (1);
//     }

//     mlx_put_image_to_window(mlx, win_player, img, 0, 0);
// 	mlx_put_image_to_window(mlx, win_backgound, img2, 50, 0);
// 	mlx_put_image_to_window(mlx, win_backgound, img3, 600, 0);

//     mlx_loop(mlx);
//     return (0);
// }



// # define WINDOW_WIDTH 600
// # define WINDOW_HEIGHT 300
// #define MLX_ERROR 1

// int main(void)
// {
//     void	*mlx_ptr;
//     void	*win_ptr;

//     mlx_ptr = mlx_init();
//     if (mlx_ptr == NULL)
//         return (MLX_ERROR);
//     win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
//     if (win_ptr == NULL)
//     {
//         free(win_ptr);
//         return (MLX_ERROR);
//     }
//     while (1)
//         ;
//     mlx_destroy_window(mlx_ptr, win_ptr);
//     mlx_destroy_display(mlx_ptr);
//     free(mlx_ptr);
// }

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;



// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }



// int	main(void)
// {
// 	t_data	img;
// 	void	*mlx;
// 	void 	*win;
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 800, 500, "Hello world!");
// 	img.img = mlx_new_image(mlx, 800, 500);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 6, 5, 0x000000FF);
// 	my_mlx_pixel_put(&img, 7, 5, 0x0000FF00);
// 	my_mlx_pixel_put(&img, 8, 5, 0x000000FF);
// 	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
// 	mlx_loop(mlx);

// }


