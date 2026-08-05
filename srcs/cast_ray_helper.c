/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:05:20 by xalves            #+#    #+#             */
/*   Updated: 2026/08/05 22:29:14 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// get player tile + direction pointing
//How far along the ray do I travel before crossing one more vertical or horizontal grid line?
void	init_ray(t_ray *ray, t_game *game, float angle)
{
	ray->map_x = game->player.x / BLOCK;
	ray->map_y = game->player.y / BLOCK;

	ray->dir_x = cos(angle);
	ray->dir_y = sin(angle);

	if (ray->dir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1.0 / ray->dir_x);

	if (ray->dir_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1.0 / ray->dir_y);
}

// steps + find first side(horizontal/vertical) distance
void	init_dda(t_ray *ray, t_game *game)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = ((game->player.x - ray->map_x * BLOCK) / BLOCK) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (((ray->map_x + 1) * BLOCK - game->player.x) / BLOCK) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = ((game->player.y - ray->map_y * BLOCK) / BLOCK) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (((ray->map_y + 1) * BLOCK - game->player.y) / BLOCK) * ray->delta_y;
	}
}

// if no wall hit on the first grid line -> jumps to next one until it hits
void	perform_dda(t_ray *ray, t_game *game)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_hit(t_ray *ray, t_game *game, float ray_angle)
{
	double	ray_length;

	if (ray->side == 0)
		ray_length = ray->side_x - ray->delta_x;
	else
		ray_length = ray->side_y - ray->delta_y;
	ray->wall_dist = ray_length * cos(ray_angle - game->player.angle);

	ray->hit_x = game->player.x + ray_length * BLOCK * ray->dir_x;
	ray->hit_y = game->player.y + ray_length * BLOCK * ray->dir_y;
}

void	render_ray(t_game *game, t_ray *ray, int x)
{
	t_img	*tex;

	game->ray_x = ray->hit_x;
	game->ray_y = ray->hit_y;

	tex = get_wall_texture(game, *ray);
	set_texture_x(game, tex, ray->hit_x, ray->hit_y);
	render_3d(game, ray->wall_dist, x, tex);
}