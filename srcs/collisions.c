/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:30:02 by xalves            #+#    #+#             */
/*   Updated: 2026/05/27 15:57:12 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// Returns 1 if pixel position (px, py) is inside a wall tile
int is_wall(t_game *game, float px, float py)
{
    int tile_x;
    int tile_y;

    tile_x = (int)px / 64;
    tile_y = (int)py / 64;
    // Guard against going out of map bounds
    /* if (tile_y < 0 || tile_x < 0 || !game->map[tile_y] || !game->map[tile_y][tile_x])
        return (1); */
    return (game->map[tile_y][tile_x] == '1');
}