/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:03:50 by xalves            #+#    #+#             */
/*   Updated: 2026/06/19 13:31:15 by xalves           ###   ########.fr       */
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
	float	sin_angle;
	float	cos_angle;

	sin_angle = sin(game->player.angle);
	cos_angle = cos(game->player.angle);
	
	look_input(key, &game->player);
	// movement
	if (key == XK_w)
	{
		game->player.x += cos_angle * PLAYER_SPEED;
		game->player.y += sin_angle * PLAYER_SPEED;
	}
	if (key == XK_s)
	{
		game->player.x -= cos_angle * PLAYER_SPEED;
		game->player.y -= sin_angle * PLAYER_SPEED;
	}
	if (key == XK_a) // strafe left. swithed - with + (and vice versa)
	{
		game->player.x += sin_angle * PLAYER_SPEED;
		game->player.y -= cos_angle * PLAYER_SPEED;
	}
	if (key == XK_d) // strafe right. swithed - with + (and vice versa)
	{
		game->player.x -= sin_angle * PLAYER_SPEED;
		game->player.y += cos_angle * PLAYER_SPEED;
	}
	/* printf("\nplayer_angle = %f", game->player.angle);
	printf("\nx = %f", game->player.x);
	printf("\ny = %f", game->player.y);
	printf("\n"); */
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
	printf("\nplayer x = %f\nplayer y = %f", game->player.x, game->player.y);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, render, game);
}



/* // "camera"
	look_input(key, &game->player);
	// movement
	if (key == XK_w)
	{
		game->player.x += game->player.plyr_dx;
		game->player.y += game->player.plyr_dy;
	}
	if (key == XK_a) // strafe left
	{
		game->player.x += game->player.plyr_dy;
		game->player.y -= game->player.plyr_dx;
	}
	if (key == XK_s)
	{
		game->player.x -= game->player.plyr_dx;
		game->player.y -= game->player.plyr_dy;
	}
	if (key == XK_d) // strafe right
	{
		game->player.x -= game->player.plyr_dy;
		game->player.y += game->player.plyr_dx;
	} */