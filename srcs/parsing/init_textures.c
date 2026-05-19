#include "parsing.h"

void free_textures(t_map *map)
{
	if(map->n_texture)
		free(map->n_texture);
	if(map->s_texture)
		free(map->s_texture);
	if(map->e_texture)
		free(map->e_texture);
	if(map->w_texture)
		free(map->w_texture);
}

int texture(t_map *map, char *line)
{
	if(line[0] == 'N' && line[1] == 'O')
	{
		map->n_texture = ft_substr(line, 3, ft_strlen(line) - 2);
		if(!map->n_texture)
			return (free_textures(map), 1);
		map->north = true;
	}
	if(line[0] == 'S' && line[1] == 'O')
	{
		map->s_texture = ft_substr(line, 3, ft_strlen(line) - 2);
		if(!map->s_texture)
			return (free_textures(map), 1);
		map->south = true;
	}
	if(line[0] == 'W' && line[1] == 'E')
	{
		map->w_texture = ft_substr(line, 3, ft_strlen(line) - 2);
		if(!map->w_texture)
			return (free_textures(map), 1);
		map->west = true;
	}
	if(line[0] == 'E' && line[1] == 'A')
	{
		map->e_texture = ft_substr(line, 3, ft_strlen(line) - 2);
		if(!map->e_texture)
			return (free_textures(map), 1);
		map->east = true;
	}
}
