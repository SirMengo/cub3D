/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:10:37 by xalves            #+#    #+#             */
/*   Updated: 2026/07/22 19:19:27 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	copy_map(t_map *map, char *line)
{
	char	**temp_map;
	int		i;

	map->row_count = 0;
	if (map->map)
		while (map->map[map->row_count])
			map->row_count++;
	temp_map = ft_calloc(map->row_count + 2, sizeof(char *));
	if (!temp_map)
		return (print_error(ST_MAPERR));
	i = 0;
	while (i < map->row_count)
	{
		temp_map[i] = map->map[i];
		i++;
	}
	replace_newline(line);
	temp_map[map->row_count] = ft_substr(line, 0, ft_strlen(line));
	if (!temp_map[map->row_count])
		return (free(temp_map), print_error(ST_MAPERR));
	temp_map[map->row_count + 1] = NULL;
	free(map->map);
	map->map = temp_map;
	return (0);
}

static int	parse_header_line(t_map *map, char *line, int *map_s, int *ret)
{
	if (!has_content(line))
		return (1);
	if ((map->north && map->south && map->west && map->east \
&& map->floor && map->ceiling) || is_valid_map_line(line))
	{
		*map_s = 1;
		*ret = copy_map(map, line);
	}
	else
		*ret = get_texture(map, line);
	return (0);
}

static int	process_line(t_map *map, char *line, int *started, int *ended)
{
	int	ret;

	if (*started)
	{
		if (!has_content(line))
		{
			*ended = 1;
			return (free(line), 2);
		}
		if (*ended)
			return (free(line), print_error(EXT_MAP));
		if (!is_valid_map_line(line))
			return (free(line), print_error(INV_CHAR));
		ret = copy_map(map, line);
	}
	else if (parse_header_line(map, line, started, &ret))
		return (free(line), 2);
	free(line);
	return (ret);
}

static int	loop(t_map *map, int *started, int *ended)
{
	char	*line;
	int		ret;

	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		replace_newline(line);
		ret = process_line(map, line, started, ended);
		if (ret == 2)
			continue ;
		if (ret)
			return (ret_check(map->fd));
	}
	return (0);
}

int	init_map(t_map *map)
{
	int	map_started;
	int	map_ended;
	int	ret;

	map->fd = open(map->file_name, O_RDONLY);
	if (map->fd < 0)
		return (print_error(FIL_EX));
	map_started = 0;
	map_ended = 0;
	ret = loop(map, &map_started, &map_ended);
	if (ret)
		return (1);
	close(map->fd);
	return (normalize_map(map));
}
