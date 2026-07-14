/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:32:27 by xalves            #+#    #+#             */
/*   Updated: 2026/07/13 17:13:15 by xalves           ###   ########.fr       */
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
float	player_start_angle(t_map *pars)
{
	if (pars->p_cardinal == 'N')
	{
		return ((3 * PI) / 2);
	}
	if (pars->p_cardinal == 'S')
	{
		return (PI / 2);
	}
	if (pars->p_cardinal == 'E')
	{
		return (0);
	}
	if (pars->p_cardinal == 'W')
	{
		return (PI);
	}
	return (0);
}

// need to modify game->player.angle so it's automatic
void	init_player(t_player *player, t_map *pars)
{
	player->x = pars->x_pos;
	player->y = pars->y_pos;
	player->angle = player_start_angle(pars);
	player->orientation = pars->p_cardinal;
}

/* game->n_texture = "srcs/textures/nort.xpm";
	game->s_texture = "srcs/textures/south.xpm";
	game->e_texture = "srcs/textures/east.xpm";
	game->w_texture = "srcs/textures/west.xpm"; */
//need to transform into an int function so i can return 1 if error
int	init_textures(t_game *game, t_map *pars)
{
	game->wall_north.img = NULL;
	game->wall_south.img = NULL;
	game->wall_east.img = NULL;
	game->wall_west.img = NULL;
	game->img.img = NULL;
	game->n_texture = pars->n_texture;
	game->s_texture = pars->s_texture;
	game->e_texture = pars->e_texture;
	game->w_texture = pars->w_texture;
	game->hex_cieling = pars->hex_cieling;
	game->hex_floor = pars->hex_floor;
	if (generate_img_ptr(game, &game->wall_north, game->n_texture) == 1)
		return (1);
	printf("\nnorth texture addr: %p\n", game->wall_north.addr);
	if (generate_img_ptr(game, &game->wall_south, game->s_texture) == 1)
		return (1);
	printf("\nsouth texture addr: %p\n", game->wall_south.addr);
	if (generate_img_ptr(game, &game->wall_east, game->e_texture) == 1)
		return (1);
	printf("\neast texture addr: %p\n", game->wall_east.addr);
	if (generate_img_ptr(game, &game->wall_west, game->w_texture) == 1)
		return (1);
	printf("\nwest texture addr: %p\n", game->wall_west.addr);
	return (0);
}

/// @brief Initiates the game, player & image variables
/// @param game 
int	init_game(t_game *game, t_map *pars)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->map = pars->map;
	init_player(&game->player, pars);
	if (init_textures(game, pars) == 1)
	{
		return (1);
	}
	init_img(&game->img, game->mlx);
	return (0);
}
