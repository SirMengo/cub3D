#include "parsing.h"

int init_map(t_map *map)
{
	char *line;
	int fd = open("file.txt", O_RDONLY);
	map->north = false;
	map->south = false;
	map->south = false;
	map->east = false;
	while ((line = get_next_line(fd)) != NULL)
	{
		texture(map, line);
		if(map->north && map->south && map->west && map->east)
		{
			printf("All textures");
			return 0;
		}
	}
	printf("Missing textures");
	return 1;
}

int parsing()
{
	int i;
	t_map *map;
	map = malloc(sizeof(t_map));
	init_map(map);
	return 0;
}

int main()
{
	parsing();
	return 0;
}	