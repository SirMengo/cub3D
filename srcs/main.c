/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:14:41 by xalves            #+#    #+#             */
/*   Updated: 2026/07/24 11:56:59 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

int	render_loop(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img);
	init_img(&game->img, game->mlx);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	*pars;

	if (argc != 2)
		return (1);
	if (parsing(&pars, argv[1]))
		return (1);
	game.pars = pars;
	if (init_game(&game, game.pars) == 1)
	{
		cleanup(&game);
		return (1);
	}
	input_check(&game);
	mlx_loop(game.mlx);
	cleanup(&game);
	return (0);
}
