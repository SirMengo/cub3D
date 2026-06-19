#include "parsing.h"

static int	parse_color_value(char **color, int *value)
{
	while (**color == ' ' || **color == '\t')
		(*color)++;
	if (!ft_isdigit(**color))
		return (print_error(INV_COLOR));
	*value = 0;
	while (ft_isdigit(**color))
	{
		*value = *value * 10 + (**color - '0');
		if (*value > 255)
			return (print_error(INV_COLOR));
		(*color)++;
	}
	while (**color == ' ' || **color == '\t')
		(*color)++;
	return (0);
}

static int	check_color(char *color, int rgb[3])
{
	if (parse_color_value(&color, &rgb[0]))
		return (1);
	if (*color != ',')
		return (print_error(INV_COLOR));
	color++;
	if (parse_color_value(&color, &rgb[1]))
		return (1);
	if (*color != ',')
		return (print_error(INV_COLOR));
	color++;
	if (parse_color_value(&color, &rgb[2]))
		return (1);
	if (*color != '\0' && *color != '\n')
		return (print_error(INV_COLOR));
	return (0);
}

static int	set_texture(char **dst, int *flag, char *line)
{
	unsigned int	start;
	size_t			end;

	if (*flag > 0)
		free(*dst);
	start = 2;
	while (line[start] == ' ' || line[start] == '\t')
		start++;
	end = ft_strlen(line);
	while (end > start && (line[end - 1] == '\n'
			|| line[end - 1] == ' ' || line[end - 1] == '\t'))
		end--;
	*dst = ft_substr(line, start, end - start);
	if (!*dst)
		return (print_error(ST_MAPERR));
	(*flag)++;
	return (0);
}

static char	*rgb_to_hex(int rgb[3])
{
	char		*hex;
	const char	*digits = "0123456789ABCDEF";
	int			i;

	hex = ft_calloc(7, sizeof(char));
	if (!hex)
		return (print_error(ST_MAPERR), NULL);
	i = 0;
	while (i < 3)
	{
		hex[i * 2] = digits[(rgb[i] >> 4) & 0xF];
		hex[i * 2 + 1] = digits[rgb[i] & 0xF];
		i++;
	}
	hex[6] = '\0';
	return (hex);
}

int	get_texture(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (set_texture(&map->n_texture, &map->north, line));
	if (!ft_strncmp(line, "SO", 2))
		return (set_texture(&map->s_texture, &map->south, line));
	if (!ft_strncmp(line, "WE", 2))
		return (set_texture(&map->w_texture, &map->west, line));
	if (!ft_strncmp(line, "EA", 2))
	{
		return (set_texture(&map->e_texture, &map->east, line));
	}
	if (!ft_strncmp(line, "C ", 2)
		&& !set_texture(&map->c_color, &map->ceiling, line)
		&& !check_color(map->c_color, map->c_rgb))
	{
		free(map->hex_cieling);
		return (!(map->hex_cieling = rgb_to_hex(map->c_rgb)));
	}
	if (!ft_strncmp(line, "F ", 2)
		&& !set_texture(&map->f_color, &map->floor, line)
		&& !check_color(map->f_color, map->f_rgb))
	{
		free(map->hex_floor);
		return (!(map->hex_floor = rgb_to_hex(map->f_rgb)));
	}
	return (1);
}
