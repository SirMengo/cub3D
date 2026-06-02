/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:03:50 by xalves            #+#    #+#             */
/*   Updated: 2026/05/28 18:41:51 by xalves           ###   ########.fr       */
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

void	player_movement(int key, t_game *game)
{
	if (key == XK_w)
		game->player_y -= 5;
	if (key == XK_a)
		game->player_x -= 5;
	if (key == XK_s)
		game->player_y += 5;
	if (key == XK_d)
		game->player_x += 5;
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
