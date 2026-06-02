/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:32:27 by xalves            #+#    #+#             */
/*   Updated: 2026/06/01 15:40:49 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_img(t_img *img, void *mlx)
{
	img->img = mlx_new_image(mlx, 1280, 720);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, \
&img->endian);
}

char	**get_map_test(void)
{
	static char	*map[] = {
		"111111111111",
		"100001000101",
		"100000010001",
		"100001000101",
		"100000010001",
		"10W000111111",
		"100000000001",
		"111111111111",
		"1 1 1 1     ",
		"1  1 1 1    ",
		"111111111111",
		NULL
	};

	return (map);
}

/*
1280, 720 = 720p
game->first_pos_set = 1; // 1 true, 0 false
*/
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1280, 720, "Cub3D");
	game->player_orientation = 'N';
	game->map = get_map_test();
	game->first_pos_set = 1;
	init_img(&game->img, game->mlx);
}
