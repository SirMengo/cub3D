/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:46:31 by xalves            #+#    #+#             */
/*   Updated: 2026/06/30 11:44:58 by xalves           ###   ########.fr       */
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

void	render_3d(t_game *game, float dist, int i, t_img *tex, float ray_x, float ray_y)
{
	float	h;
	int		start;
	int		end;
	int		tx;
	int		y;
	int		ty;
	int		color;

	h = (BLOCK / dist) * (HEIGHT);
	start = (HEIGHT - h) / 2;
	end = start + h;
	if (tex == &game->wall_west || tex == &game->wall_east)
		tx = ((int)ray_y % 64 + 64) % 64;
	else
		tx = ((int)ray_x % 64 + 64) % 64;
	// Flip west and south textures
	if (tex == &game->wall_west || tex == &game->wall_south)
		tx = 63 - tx;
	y = 0;
	while (y < start)
	{
		draw_pixel(&game->img, i, y, 0x00FFFF);
		y++;
	}
	while (y < end && y < HEIGHT)
	{
		ty = ((y - start) * 64) / (int)h;
		if (ty > 64)
			ty = 64;
		color = get_texture_pixel_color(tex, tx, ty);
		draw_pixel(&game->img, i, y, color);
		y++;
	}
	while (y < HEIGHT)
	{
		draw_pixel(&game->img, i, y, 0x8B4513);
		y++;
	}
}

void	fan_raycast(t_game *game, float angle, float fov)
{
	float	rx;
	float	ry;
	float	cx;
	float	cy;
	float	dist;
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		rx = game->player.x;
		ry = game->player.y;
		cx = cos(angle);
		cy = sin(angle);
		while (!ray_hitting_wall(rx, ry, game))
		{
			rx += cx;
			ry += cy;
		}
		dist = distance(rx - game->player.x, ry - game->player.y);
		dist = dist * cos(angle - game->player.angle);
		render_3d(game, dist, i, get_wall_texture(game, rx, ry), rx, ry);
		angle = normalize_angle(angle + (fov / WIDTH));
		i++;
	}
}

void	raycast(t_game *game)
{
	float	fov;

	fov = degrees_to_radians(FOV);
	fan_raycast(game, normalize_angle(game->player.angle - (fov / 2)), fov);
}
