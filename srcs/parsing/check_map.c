/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:22:38 by xalves            #+#    #+#             */
/*   Updated: 2026/07/22 19:22:40 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int	is_open_tile(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	check_sides(t_map *map, int i, int j)
{
	if (!is_open_tile(map->map[i][j]))
		return (0);
	if (j + 1 >= (int)ft_strlen(map->map[i])
		|| is_whitespace(map->map[i][j + 1]))
		return (1);
	if (j - 1 < 0 || is_whitespace(map->map[i][j - 1]))
		return (1);
	if (!map->map[i + 1] || is_whitespace(map->map[i + 1][j]))
		return (1);
	if (i - 1 < 0 || is_whitespace(map->map[i - 1][j]))
		return (1);
	return (0);
}

int	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (i == 0 || !map->map[i + 1])
			{
				if (map->map[i][j] != '1' && map->map[i][j] != ' ')
					return (print_error(MAP_SIDES));
			}
			else if (check_sides(map, i, j))
				return (print_error(MAP_SIDES));
			j++;
		}
		i++;
	}
	return (0);
}
