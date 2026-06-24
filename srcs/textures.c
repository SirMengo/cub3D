/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:33:40 by xalves            #+#    #+#             */
/*   Updated: 2026/06/24 17:45:28 by xalves           ###   ########.fr       */
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
		printf("Error\n On loading texture: %s\n", xpm_path);
		return ;
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, \
&texture->line_len, &texture->endian);
}
