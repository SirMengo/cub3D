#include "parsing.h"

void free_textures(t_map *map)
{
	free(map->n_texture);
	free(map->s_texture);
	free(map->e_texture);
	free(map->w_texture);
}

static int set_texture(t_map *map, char **dst, bool *flag, char *line)
{
	*dst = ft_substr(line, 3, ft_strlen(line) - 2);
	if(!*dst)
		return (free_textures(map), 1);
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
}
