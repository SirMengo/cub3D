#include "parsing.h"

static int parse_color_value(char **color, int *value)
{
	while (**color == ' ' || **color == '\t')
		(*color)++;
	if (!ft_isdigit(**color))
		return (1);
	*value = 0;
	while (ft_isdigit(**color))
	{
		*value = *value * 10 + (**color - '0');
		if (*value > 255)
			return (1);
		(*color)++;
	}
	while (**color == ' ' || **color == '\t')
		(*color)++;
	return (0);
}

int check_color(char *color, int rgb[3])
{
	if (parse_color_value(&color, &rgb[0]))
		return (1);
	if (*color != ',')
		return (1);
	color++;
	if (parse_color_value(&color, &rgb[1]))
		return (1);
	if (*color != ',')
		return (1);
	color++;
	if (parse_color_value(&color, &rgb[2]))
		return (1);
	if (*color != '\0' && *color != '\n')
		return (1);
	return (0);
}

static int set_texture(t_map *map, char **dst, bool *flag, char *line)
{
	unsigned int	start;
	size_t			end;

	start = 2;
	while (line[start] == ' ' || line[start] == '\t')
		start++;
	end = ft_strlen(line);
	while (end > start && (line[end - 1] == '\n' || line[end - 1] == ' ' || line[end - 1] == '\t'))
		end--;
	*dst = ft_substr(line, start, end - start);
	if (!*dst)
		return (free_map(map), 1);
	*flag = true;
	return (0);
	
}

static char *rgb_to_hex(t_map *map, int rgb[3])
{
    char		*hex;
	const char	*digits = "0123456789ABCDEF";
	int			i;

	hex = ft_calloc(7, sizeof(char));
	if (!hex)
		return (free_map(map), NULL);
	i = 0;
	while (i < 3)
	{
		hex[i * 2]     = digits[(rgb[i] >> 4) & 0xF];
		hex[i * 2 + 1] = digits[rgb[i] & 0xF];
		i++;
	}
	hex[6] = '\0';
	return (hex);
}

int get_texture(t_map *map, char *line)
{
	if(!ft_strncmp(line, "NO", 2))
		return (set_texture(map, &map->n_texture, &map->north, line));
	if(!ft_strncmp(line, "SO", 2))
		return (set_texture(map, &map->s_texture, &map->south, line));
	if(!ft_strncmp(line, "WE", 2))
		return (set_texture(map, &map->w_texture, &map->west, line));
	if(!ft_strncmp(line, "EA", 2))
		return (set_texture(map, &map->e_texture, &map->east, line));
	if (!ft_strncmp(line, "C ", 2) && !set_texture(map, &map->c_color, &map->ceiling, line)
		&& !check_color(map->c_color, map->c_rgb))
		return (!(map->hex_cieling = rgb_to_hex(map, map->c_rgb)));
	if (!ft_strncmp(line, "F ", 2) && !set_texture(map, &map->f_color, &map->floor, line)
		&& !check_color(map->f_color, map->f_rgb))
		return (!(map->hex_floor = rgb_to_hex(map, map->f_rgb)));
	return (1);
}
