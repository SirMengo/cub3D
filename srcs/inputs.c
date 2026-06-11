/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:03:50 by xalves            #+#    #+#             */
/*   Updated: 2026/06/11 12:00:12 by xalves           ###   ########.fr       */
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

/* 
void	player_movement(int key, t_game *game)
{
	float aux_x;
	float aux_y;

	aux_x = game->player_x;
	aux_y = game->player_y;
	if (key == XK_w)
		aux_y -= 5;
	if (key == XK_a)
		aux_x -= 5;
	if (key == XK_s)
		aux_y += 5;
	if (key == XK_d)
		aux_x += 5;
	if (!is_wall(game, aux_x, aux_y))
	{
		game->player_x = aux_x;
		game->player_y = aux_y;
	}
}
*/

void	look_input(int key, t_player *player)
{
	if (key == XK_Left)
	{
		player->plyr_angle += CAM_SENS;//due to -sin, I change -= to +=
		if (player->plyr_angle < 0)
		{
			player->plyr_angle += 2 * PI;
		}
		player->plyr_dx = cos(player->plyr_angle) * PLAYER_SPEED;
		player->plyr_dy = -sin(player->plyr_angle) * PLAYER_SPEED;
	}
	if (key == XK_Right)
	{
		player->plyr_angle -= CAM_SENS;//due to -sin, I change += to -=
		if (player->plyr_angle > 2 * PI)
		{
			player->plyr_angle -= 2 * PI;
		}
		player->plyr_dx = cos(player->plyr_angle) * PLAYER_SPEED;
		player->plyr_dy = -sin(player->plyr_angle) * PLAYER_SPEED;
	}
}

//need to see if i can just pass player instead of game !!!
void	player_movement(int key, t_game *game)
{
	// "camera"
	look_input(key, &game->player);
	// movement
	if (key == XK_w)
	{
		game->player.plyr_x += game->player.plyr_dx;
		game->player.plyr_y += game->player.plyr_dy;
	}
	if (key == XK_a) // strafe left
	{
		game->player.plyr_x += game->player.plyr_dy;
		game->player.plyr_y -= game->player.plyr_dx;
	}
	if (key == XK_s)
	{
		game->player.plyr_x -= game->player.plyr_dx;
		game->player.plyr_y -= game->player.plyr_dy;
	}
	if (key == XK_d) // strafe right
	{
		game->player.plyr_x -= game->player.plyr_dy;
		game->player.plyr_y += game->player.plyr_dx;
	}
}

int	key_press(int key, t_game *game)
{
	if (key == XK_Escape)
		close_window(game);
	player_movement(key, game);
	return (0);
}

void	input_check(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, render, game);
}
