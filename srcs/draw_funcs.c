/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:03:32 by xalves            #+#    #+#             */
/*   Updated: 2026/06/08 14:26:58 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
//image out of bounds //image out of bounds
void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= 1280 || y < 0 || y >= 720)
	{
		return ;
	}
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_direction_line(t_game *game, int length, int width, int color)
{
	float	x;
	float	y;
	int		i;

	i = 0;
	while (i < length)
	{
		x = (game->player.plyr_x + 4) + game->player.plyr_dx / PLAYER_SPEED * i;
		y = (game->player.plyr_y + 4) + game->player.plyr_dy / PLAYER_SPEED * i;
		draw_square(&game->img, (int)x - width / 2, (int)y - width / 2, \
width, color);
		i++;
	}
}

/// @brief draw square in (sx,sy) with size and color
/// @param img image
/// @param sx starting position on x axis
/// @param sy starting position on y axis
/// @param size square size/dimention
/// @param color color of square
// (!!! Number of args problem might get resolved with singletons !!!)
void	draw_square(t_img *img, int sx, int sy, int size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			draw_pixel(img, sx + x, sy + y, color);
			x++;
		}
		y++;
	}
}
