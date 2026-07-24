/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:22:22 by xalves            #+#    #+#             */
/*   Updated: 2026/07/22 19:22:24 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	free(map->n_texture);
	free(map->s_texture);
	free(map->e_texture);
	free(map->w_texture);
	free(map->c_color);
	free(map->f_color);
	free(map->hex_cieling);
	free(map->hex_floor);
	free(map->file_name);
	i = 0;
	if (map->map)
	{
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
	}
	free(map);
}
