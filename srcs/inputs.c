/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:03:50 by xalves            #+#    #+#             */
/*   Updated: 2026/07/14 11:57:59 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_and_destroy_img(void	*mlx, void	*img)
{
	if (img)
	{
		mlx_destroy_image(mlx, img);
	}
}

void	cleanup(t_game *game)
{
	check_and_destroy_img(game->mlx, game->img.img);
	check_and_destroy_img(game->mlx, game->wall_north.img);
	check_and_destroy_img(game->mlx, game->wall_south.img);
	check_and_destroy_img(game->mlx, game->wall_east.img);
	check_and_destroy_img(game->mlx, game->wall_west.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
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

//printf("\nplayer x = %f\nplayer y = %f", game->player.x, game->player.y);
//mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
//mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release, game);
void	input_check(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, DestroyNotify, 0, close_window, game);
	mlx_loop_hook(game->mlx, render_loop, game);
}
