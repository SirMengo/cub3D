/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:33:40 by xalves            #+#    #+#             */
/*   Updated: 2026/08/02 16:04:12 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	generate_img_ptr(t_game *game, t_img *texture, char *xpm_path)
{
	int	size;

	size = SPRITE_SIZE;
	texture->img = mlx_xpm_file_to_image(game->mlx, xpm_path, &size, &size);
	if (!texture->img)
	{
		print_error("Error loading texture\n");
		return (1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, \
&texture->line_len, &texture->endian);
	return (0);
}

int	get_texture_pixel_color(t_img *texture, int x, int y)
{
	char	*pixel;
	int		color;

	if (x < 0 || y < 0 || x >= SPRITE_SIZE || y >= SPRITE_SIZE)
		return (0);
	pixel = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

t_img	*get_wall_texture(t_game *game, t_ray ray)
{
	if (ray.side == 0)
	{
		if (ray.step_x > 0)
			return (&game->wall_east);
		return (&game->wall_west);
	}
	else
	{
		if (ray.step_y > 0)
			return (&game->wall_south);
		return (&game->wall_north);
	}
}

void	set_texture_x(t_game *game, t_img *tex, float rx, float ry)
{
	int	tx;

	if (tex == &game->wall_west || tex == &game->wall_east)
		tx = ((int)ry % 64 + 64) % 64;
	else
		tx = ((int)rx % 64 + 64) % 64;
	if (tex == &game->wall_west || tex == &game->wall_south)
		tx = 63 - tx;
	game->tex_x = tx;
}
