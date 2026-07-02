/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:32:27 by xalves            #+#    #+#             */
/*   Updated: 2026/07/02 02:47:46 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_img(t_img *img, void *mlx)
{
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, \
&img->endian);
}

/// @brief finds and inits players starting position
/// @param game (might change, depends on what i recieve from parse)
void	find_player_start_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (detect_player(game->map[y][x]))
			{
				game->player.x = (x * 64) + 28;
				game->player.y = (y * 64) + 28;
				return ;
			}
			x++;
		}
		y++;
	}
}

// need to modify game->player.angle so it's automatic
void	init_player(t_game *game)
{
	find_player_start_pos(game);
	game->player.angle = (3 * PI) / 2;
	game->player.orientation = 'N';
}

//need to transform into an int function so i can return 1 if error
void	init_textures(t_game *game)
{
	game->n_texture = "srcs/textures/north.xpm";
	game->s_texture = "srcs/textures/south.xpm";
	game->e_texture = "srcs/textures/east.xpm";
	game->w_texture = "srcs/textures/west.xpm";
	generate_img_ptr(game, &game->wall_north, game->n_texture);
	printf("\nnorth texture addr: %p\n", game->wall_north.addr);
	generate_img_ptr(game, &game->wall_south, game->s_texture);
	printf("\nsouth texture addr: %p\n", game->wall_south.addr);
	generate_img_ptr(game, &game->wall_east, game->e_texture);
	printf("\neast texture addr: %p\n", game->wall_east.addr);
	generate_img_ptr(game, &game->wall_west, game->w_texture);
	printf("\nwest texture addr: %p\n", game->wall_west.addr);
}

/// @brief Initiates the game, player & image variables
/// @param game 
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->map = get_map_test();
	init_textures(game);
	init_player(game);
	init_img(&game->img, game->mlx);
}
