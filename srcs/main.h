/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:54:22 by xalves            #+#    #+#             */
/*   Updated: 2026/05/27 14:30:52 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	float	player_x;
	float	player_y;
	char	player_orientation;
	int		first_pos_set;
	char	**map;
}	t_game;

//main.c
int		render(t_game *game);

//init.c
void	init_game(t_game *game);
void	init_img(t_img *img, void *mlx);

//inputs.c
void	input_check(t_game *game);

//draw_funcs.c
void	draw_pixel(t_img *img, int x, int y, int color);
void	draw_square(t_img *img, int sx, int sy, int size, int color);

//collisions.c
int is_wall(t_game *game, float px, float py);

#endif