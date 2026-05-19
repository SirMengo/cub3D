#include "parsing.h"

void init_map(t_map *map)
{
	char *line;
	int fd = open("file.txt", O_RDONLY);
	int i = 2;
	while ((line = get_next_line(fd)) != NULL)
	{
		if(line[0] == 'N' && line[1] == 'O')
		{
			map->n_texture = ft_substr(line, 3, ft_strlen(line) - 2);
			//if(!map->n_texture)
				//free funct
		}
	}
}

int parsing()
{
	int i;
	t_map *map;
	map = malloc(sizeof(t_map));
	init_map(map);
	printf("%s", map->n_texture);
	return 0;
}

int main()
{
	parsing();
	return 0;
}	