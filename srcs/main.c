/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:14:41 by xalves            #+#    #+#             */
/*   Updated: 2026/07/07 13:38:34 by xalves           ###   ########.fr       */
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

int	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

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

/* void	draw_player(t_game *game)
{
	draw_square(&game->img, game->player.x, game->player.y, 9, 0xFD5CCD);
} */

//+32 just to center the player on the floor
void	set_player_pos(t_game *game, int x, int y)
{
	if (game->first_pos_set == 1)
	{
		game->player.x = (x * BLOCK) + 32;
		game->player.y = (y * BLOCK) + 32;
		game->first_pos_set = 0;
	}
}

//render_map(game);
//draw_player(game);
int	render_loop(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img);
	init_img(&game->img, game->mlx);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_game	game;

	if (init_game(&game) == 1 )
	{
		cleanup(&game);
		return (1);
	}
	input_check(&game);
	mlx_loop(game.mlx);
	return (0);
}
