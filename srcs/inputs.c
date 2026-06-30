/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:03:50 by xalves            #+#    #+#             */
/*   Updated: 2026/06/30 14:32:15 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	close_window(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

int	is_wall(t_game *game, float px, float py)
{
	int	tile_x;
	int	tile_y;

	tile_x = (int)px / BLOCK;
	tile_y = (int)py / BLOCK;
	if (tile_y < 0 || tile_x < 0 || !game->map[tile_y] || !game->map[tile_y][tile_x])
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
}

//need to see if i can just pass player instead of game !!!
void	player_movement(int key, t_game *game)
{
	float	x_aux;
	float	y_aux;
	float	sin_angle;
	float	cos_angle;

	x_aux = game->player.x;
	y_aux = game->player.y;
	sin_angle = sin(game->player.angle);
	cos_angle = cos(game->player.angle);

	look_input(key, &game->player);
	// movement
	if (key == XK_w)
	{
		x_aux += cos_angle * PLAYER_SPEED;
		y_aux += sin_angle * PLAYER_SPEED;
	}
	if (key == XK_s)
	{
		x_aux -= cos_angle * PLAYER_SPEED;
		y_aux -= sin_angle * PLAYER_SPEED;
	}
	if (key == XK_a)
	{
		x_aux += sin_angle * PLAYER_SPEED;
		y_aux -= cos_angle * PLAYER_SPEED;
	}
	if (key == XK_d)
	{
		x_aux -= sin_angle * PLAYER_SPEED;
		y_aux += cos_angle * PLAYER_SPEED;
	}
	if (!is_wall(game, x_aux, y_aux))
	{
		game->player.x = x_aux;
		game->player.y = y_aux;
	}
}

int	key_press(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		close_window(game);
	}
	player_movement(key, game);
	return (0);
}

void	input_check(t_game *game)
{
	//printf("\nplayer x = %f\nplayer y = %f", game->player.x, game->player.y);
	//mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
    //mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, DestroyNotify, 0, close_window, game);
	mlx_loop_hook(game->mlx, render_loop, game);
}
