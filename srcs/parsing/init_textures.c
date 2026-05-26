#include "parsing.h"

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
