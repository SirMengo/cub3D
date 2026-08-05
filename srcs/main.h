/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:54:22 by xalves            #+#    #+#             */
/*   Updated: 2026/08/05 22:25:37 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "parsing/parsing.h"
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
# define FOV 60
# define SPRITE_SIZE 64
# define MINIMAP_BLOCK 10

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		loaded;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	sin_angle;
	float	cos_angle;
	float	angle;
	char	orientation;
}	t_player;

typedef struct s_ray
{
	int		map_x;
	int		map_y;

	double	dir_x;
	double	dir_y;

	double	delta_x;
	double	delta_y;

	double	side_x;
	double	side_y;

	int		step_x;
	int		step_y;

	int		side;
	int		hit;

	double	wall_dist;

	double	hit_x;
	double	hit_y;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	t_map		*pars;
	int			first_pos_set;
	char		**map;
	int			map_x;
	int			map_y;
	int			tex_x;
	char		*n_texture;
	char		*s_texture;
	char		*e_texture;
	char		*w_texture;
	t_img		wall_north;
	t_img		wall_south;
	t_img		wall_east;
	t_img		wall_west;
	char		*hex_cieling;
	char		*hex_floor;
	float		ray_x;
	float		ray_y;
}	t_game;

//main.c
int		render_loop(t_game *game);
int		detect_player(char pos);
void	set_player_pos(t_game *game, int x, int y);
//int		print_error(char *str);


//init.c
int		init_game(t_game *game, t_map *pars);
void	init_img(t_img *img, void *mlx);

//inputs.c
void	input_check(t_game *game);
void	cleanup(t_game *game);

//draw_funcs.c
void	draw_pixel(t_img *img, int x, int y, int color);
//void	draw_direction_line(t_game *game, int length, int width, int color);
//void	draw_square(t_img *img, int sx, int sy, int size, int color);

//collisions.c
int		hits_wall(t_game *game, float x, float y);

//raycast.c
void	raycast(t_game *game);
void	render_3d(t_game *game, float dist, int x, t_img *tex);

//texture.c
int		generate_img_ptr(t_game *game, t_img *texture, char *xpm_path);
int		get_texture_pixel_color(t_img *texture, int x, int y);
t_img	*get_wall_texture(t_game *game, t_ray ray);
void	set_texture_x(t_game *game, t_img *tex, float rx, float ry);

//math_funcs.c
float	normalize_angle(float angle);
double	degrees_to_radians(double degrees);
float	distance(float x, float y);
int		hex_to_int(const char *hex);

//movement.c
void	player_movement(int key, t_game *game);


void	set_texture_x(t_game *game, t_img *tex, float rx, float ry);
void	cast_ray(t_game *game, float angle, int i);

// cast_ray_helper.c
void	init_ray(t_ray *ray, t_game *game, float angle);
void	init_dda(t_ray *ray, t_game *game);
void	perform_dda(t_ray *ray, t_game *game);
void	calculate_hit(t_ray *ray, t_game *game, float ray_angle);
void	render_ray(t_game *game, t_ray *ray, int column);

#endif