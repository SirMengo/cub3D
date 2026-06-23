/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:54:22 by xalves            #+#    #+#             */
/*   Updated: 2026/06/23 12:27:11 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "aux/libft/libft.h"
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# define WIDTH 1280 // # define WIDTH 1920
# define HEIGHT 720  //# define HEIGHT 1080
# define BLOCK 64
# define PI 3.14159265359
# define PLAYER_SPEED 5
# define CAM_SENS 0.1
# define FOV 90
# define MINIMAP_BLOCK 10

/* typedef struct s_ray
{
	int		r;//ray
	int		map_x;
	int		map_y;
	int		map_point;
	int		dof;//dept of field
	float	ray_x;
	float	ray_y;
	float	ray_angl;
	float	x_ofset;
	float	y_ofset;
	float	invtan;//Invert of Tangent(TAN)
}	t_ray; */

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	plyr_dx;
	float	plyr_dy;
	float	angle;
	char	orientation;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	int			first_pos_set;
	char		**map;
	int			map_x;
	int			map_y;
}	t_game;

//main.c
int		render(t_game *game);
int		detect_player(char pos);

//init.c
void	init_game(t_game *game);
void	init_img(t_img *img, void *mlx);

//inputs.c
void	input_check(t_game *game);

//draw_funcs.c
void	draw_pixel(t_img *img, int x, int y, int color);
void	draw_direction_line(t_game *game, int length, int width, int color);
void	draw_square(t_img *img, int sx, int sy, int size, int color);

//collisions.c
int		is_wall(t_game *game, float px, float py);

//raycast.c
void	raycast(t_game *game);

#endif