/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:56:18 by xalves            #+#    #+#             */
/*   Updated: 2026/08/05 12:07:40 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_wall(t_game *game, float px, float py)
{
	int	tile_x;
	int	tile_y;

	tile_x = (int)px / BLOCK;
	tile_y = (int)py / BLOCK;
	if (tile_y < 0 || tile_x < 0 || \
!game->map[tile_y] || !game->map[tile_y][tile_x])
		return (1);
	return (game->map[tile_y][tile_x] == '1');
}

int	hits_wall(t_game *game, float x, float y)
{
	int	margin;

	margin = 10;
	return (is_wall(game, x + margin, y + margin) \
|| is_wall(game, x - margin, y + margin) \
|| is_wall(game, x + margin, y - margin) \
|| is_wall(game, x - margin, y - margin));
}
