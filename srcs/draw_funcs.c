/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:03:32 by xalves            #+#    #+#             */
/*   Updated: 2026/05/26 14:15:44 by xalves           ###   ########.fr       */
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
