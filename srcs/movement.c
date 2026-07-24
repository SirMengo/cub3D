/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:51:43 by xalves            #+#    #+#             */
/*   Updated: 2026/07/24 11:52:18 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_wall(t_game *game, float px, float py)
{
	int	tile_x;
	int	tile_y;

	tile_x = (int)px / BLOCK;
	tile_y = (int)py / BLOCK;
	if (tile_y < 0 || tile_x < 0 || \
!game->map[tile_y] || !game->map[tile_y][tile_x])
		return (1);
	return (game->map[tile_y][tile_x] == '1');
}

void	look_input(int key, t_player *player)
{
	if (key == XK_Left)
		player->angle -= CAM_SENS;
	if (key == XK_Right)
		player->angle += CAM_SENS;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	player->sin_angle = sin(player->angle);
	player->cos_angle = cos(player->angle);
}

void	move_input(int key, t_game *game, float *x, float *y)
{
	if (key == XK_w)
	{
		*x += game->player.cos_angle * PLAYER_SPEED;
		*y += game->player.sin_angle * PLAYER_SPEED;
	}
	if (key == XK_s)
	{
		*x -= game->player.cos_angle * PLAYER_SPEED;
		*y -= game->player.sin_angle * PLAYER_SPEED;
	}
	if (key == XK_a)
	{
		*x += game->player.sin_angle * PLAYER_SPEED;
		*y -= game->player.cos_angle * PLAYER_SPEED;
	}
	if (key == XK_d)
	{
		*x -= game->player.sin_angle * PLAYER_SPEED;
		*y += game->player.cos_angle * PLAYER_SPEED;
	}
}

void	move_player(t_game *game, float x_aux, float y_aux)
{
	if (!is_wall(game, x_aux, y_aux))
	{
		game->player.x = x_aux;
		game->player.y = y_aux;
	}
}

void	player_movement(int key, t_game *game)
{
	float	x_aux;
	float	y_aux;

	x_aux = game->player.x;
	y_aux = game->player.y;
	look_input(key, &game->player);
	move_input(key, game, &x_aux, &y_aux);
	move_player(game, x_aux, y_aux);
}
