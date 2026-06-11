/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:14:41 by xalves            #+#    #+#             */
/*   Updated: 2026/06/05 17:04:32 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
Get screen width and height
int screen_w;
int screen_h;

game.mlx = mlx_init();
mlx_get_screen_size(game.mlx, &screen_w, &screen_h);
game.win = mlx_new_window(game.mlx, screen_w, screen_h, "Cub3D");
*/
int	detect_player(char pos)
{
	if (pos == 'N')
		return (1);
	if (pos == 'S')
		return (1);
	if (pos == 'E')
		return (1);
	if (pos == 'W')
		return (1);
	return (0);
}

void	draw_player(t_game *game)
{
	draw_square(&game->img, game->player.plyr_x, game->player.plyr_y, 9, 0xFD5CCD);
}

//+28 just to center the player on the floor
void	set_player_pos(t_game *game, int x, int y)
{
	if (game->first_pos_set == 1)
	{
		game->player.plyr_x = (x * 64) + 28;
		game->player.plyr_y = (y * 64) + 28;
		game->first_pos_set = 0;
	}
}

//draw floor and set player starting position
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_square(&game->img, x * 64, y * 64, 63, 0x7F7F7F);
			if (game->map[y][x] == '0')
				draw_square(&game->img, x * 64, y * 64, 63, 0xFFFFFF);
			if (detect_player(game->map[y][x]))
			{
				draw_square(&game->img, x * 64, y * 64, 63, 0xFFFFFF);
			}
			x++;
		}
		y++;
	}
}

int	render(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img);
	init_img(&game->img, game->mlx);
	render_map(game);
	draw_player(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_game	game;

	init_game(&game);
	input_check(&game);
	mlx_loop(game.mlx);
	return (0);
}
