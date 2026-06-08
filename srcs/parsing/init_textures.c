#include "parsing.h"

static int parse_color_value(char *color, int *value, char **end)
{
	unsigned int	i;
	size_t			len;
	char			*aux;
	
	i = 0;
	len = 0;
	while(color[i] = ' ' || color[i] == '\t')
		i++;
	if(!ft_isdigit(color[i]))
		return (1);
	*value = 0;
	while(ft_isdigit(color[i]))
	{
		*value = *value * 10 + (color[i] - '0');
		if(*value > 255)
			return (1);
		i++;
	}
	while(color[i] = ' ' || color[i] == '\t')
		i++;
	return (0);
}

int check_color(char *color, int *r, int *g, int *b)
{
	char	*ptr;

	ptr = color;
	if (parse_color_value(ptr, r, &ptr))
		return (1);
	if (*ptr != ',')
		return (1);
	ptr++;
	if (parse_color_value(ptr, g, &ptr))
		return (1);
	if (*ptr != ',')
		return (1);
	ptr++;
	if (parse_color_value(ptr, b, &ptr))
		return (1);
	if (*ptr != '\0' && *ptr != '\n')
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
	if(!ft_strncmp(line, "C ", 2))
		return (set_texture(map, &map->c_color, &map->ceiling, line));
	if(!ft_strncmp(line, "F ", 2))
		return (set_texture(map, &map->f_color, &map->floor, line));
	return (1);
}
