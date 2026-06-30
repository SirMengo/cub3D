/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:33:40 by xalves            #+#    #+#             */
/*   Updated: 2026/06/30 11:39:24 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	generate_img_ptr(t_game *game, t_img *texture, char *xpm_path)
{
	int	size;

	size = SPRITE_SIZE;
	texture->img = mlx_xpm_file_to_image(game->mlx, xpm_path, \
&size, &size);
	if (!texture->img)
	{
		printf("Error\n On loading texture: %s\n", xpm_path); //neds to be an error message on fd 2
		return ;
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, \
&texture->line_len, &texture->endian);
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

t_img	*get_wall_texture(t_game *game, float ray_x, float ray_y)
{
	float	fx;
	float	fy;

	fx = fmod(ray_x, 64);
	fy = fmod(ray_y, 64);
	if (fx < fy && fx < 64 - fy)
		return (&game->wall_east);
	if (fx > 64 - fy && fx > fy)
		return (&game->wall_west);
	if (fy < fx && fy < 64 - fx)
		return (&game->wall_south);
	return (&game->wall_north);
}
