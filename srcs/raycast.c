/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:46:31 by xalves            #+#    #+#             */
/*   Updated: 2026/08/05 22:26:10 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ray_hitting_wall(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (game->map[y][x] == '1')
	{
		return (1);
	}
	return (0);
}

void	render_3d(t_game *game, float dist, int x, t_img *tex)
{
	float	h;
	float	proj;
	int		start;
	int		y;
	int		ty;

	proj = (WIDTH / 2.0) / tan(degrees_to_radians(FOV / 2.0));
	h = proj / dist;
	start = (HEIGHT - h) / 2;
	y = 0;
	while (y < start)
		draw_pixel(&game->img, x, y++, hex_to_int(game->hex_cieling));
	while (y < start + h && y < HEIGHT)
	{
		ty = ((y - start) * 64) / (int)h;
		if (ty >= 64)
			ty = 63;
		draw_pixel(&game->img, x, y++,
			get_texture_pixel_color(tex, game->tex_x, ty));
	}
	while (y < HEIGHT)
		draw_pixel(&game->img, x, y++, hex_to_int(game->hex_floor));
}

void	cast_ray(t_game *game, float angle, int x)
{
	t_ray	ray;

	init_ray(&ray, game, angle);
	init_dda(&ray, game);
	perform_dda(&ray, game);
	calculate_hit(&ray, game, angle);
	/* if (x == WIDTH / 2)
	{
		printf("wall_dist = %f\n", ray.wall_dist);
		printf("hit = (%f, %f)\n", ray.hit_x, ray.hit_y);
		printf("player = (%f, %f)\n", game->player.x, game->player.y);
		printf("map = (%d, %d)\n", ray.map_x, ray.map_y);
		printf("side = %d\n", ray.side);
		printf("dir = (%f, %f)\n", ray.dir_x, ray.dir_y);
	} */
	render_ray(game, &ray, x);
}


/*
void	cast_ray(t_game *game, float angle, int i)
{
	float	cx;
	float	cy;
	float	dist;
	t_img	*tex;

	game->ray_x = game->player.x;
	game->ray_y = game->player.y;
	cx = cos(angle);
	cy = sin(angle);
	while (!ray_hitting_wall(game->ray_x, game->ray_y, game))
	{
		game->ray_x += cx;
		game->ray_y += cy;
	}
	dist = distance(game->ray_x - game->player.x, game->ray_y - game->player.y);
	dist = dist * cos(angle - game->player.angle);
	tex = get_wall_texture(game, game->ray_x, game->ray_y);
	set_texture_x(game, tex, game->ray_x, game->ray_y);
	render_3d(game, dist, i, tex);
} */

void	fan_raycast(t_game *game, float angle, float fov)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		cast_ray(game, angle, x);
		angle = normalize_angle(angle + (fov / WIDTH));
		x++;
	}
}

void	raycast(t_game *game)
{
	float	fov;

	fov = degrees_to_radians(FOV);
	fan_raycast(game, normalize_angle(game->player.angle - (fov / 2)), fov);
}
