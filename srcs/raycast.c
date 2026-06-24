/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:46:31 by xalves            #+#    #+#             */
/*   Updated: 2026/06/24 18:21:47 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

float	normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

float	degrees_to_radians(int degrees)
{
	return (degrees * PI / 180);
}

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

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

void render_3d(t_game *game, float dist, int i)
{
	float	height;
	int		start_y;
	int		end;
	int		y;

	height = (BLOCK / dist) * (HEIGHT / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	if (start_y < 0)
		start_y = 0;
	if (end > HEIGHT)
		end = HEIGHT;
	//celing
	y = 0;
	while (y < start_y)
	{
		draw_pixel(&game->img, i, y, 0x00FFFF);
		y++;
	}
	//wall
	y = start_y;
	while (y < end)
	{
		draw_pixel(&game->img, i, y, 0x228B22);
		y++;
	}
	//floor
	y = end;
	while (y < HEIGHT)
	{
		draw_pixel(&game->img, i, y, 0x8B4513);
		y++;
	}
}

void	fan_raycast(t_game *game, float current_angle, float fov_rad)
{
	float	ray_x;
	float	ray_y;
	float	cos_angle;
	float	sin_angle;
	float	swept;
	float	dist;
	int		i;

	swept = 0;
	i = 0;
	while (swept < fov_rad)
	{
		ray_x = game->player.x;
		ray_y = game->player.y;
		cos_angle = cos(current_angle);
		sin_angle = sin(current_angle);
		while (!ray_hitting_wall(ray_x, ray_y, game))
		{
			draw_pixel(&game->img, ray_x, ray_y, 0x4F7942);
			ray_x += cos_angle;
			ray_y += sin_angle;
		}
		dist = distance(ray_x - game->player.x, ray_y - game->player.y);
		dist = dist * cos(current_angle - game->player.angle); // fisheye fix
		render_3d(game, dist, i);
		current_angle = normalize_angle(current_angle + (fov_rad / WIDTH));
		swept += (fov_rad / WIDTH);
		i++;
	}
}



void	raycast(t_game *game)
{
	float	fov_rad;
	float	start_angle;

	fov_rad = degrees_to_radians(FOV);
	start_angle = normalize_angle(game->player.angle - (fov_rad / 2));
	fan_raycast(game, start_angle, fov_rad);
}
