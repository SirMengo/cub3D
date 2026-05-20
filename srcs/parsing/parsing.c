#include "parsing.h"

int init_map(t_map *map)
{
	char *line;
	int fd = open("file.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		get_texture(map, line);
		if(map->north && map->south && map->west && map->east && map->floor, map->ceiling)
			return 0;
	}
	return 1;
}

int parsing()
{
	int i;
	t_map *map;
	map = ft_calloc(1, sizeof(t_map));
	init_map(map);
	return 0;
}

int main()
{
	parsing();
	return 0;
}	