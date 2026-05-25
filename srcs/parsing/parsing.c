#include "parsing.h"

int has_content(char *line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if(line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int init_map(t_map *map)
{
	char	*line;
	int		fd ;

	fd = open("file.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		if(!has_content(line))
		{
			free(line);
			continue ;
		}
		if(map->north && map->south && map->west && map->east && map->floor && map->ceiling)
			copy_map(map, line);
		else
			get_texture(map, line);
		free(line);
	}
	int i = 0;
	normalize_map(map);
	while(map->map[i])
	{
		printf("%s", map->map[i]);
		printf("\\0\n");
		i++;
	}
	return 1;
}

int parsing()
{
	int		i;
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	init_map(map);
	return 0;
}

int main()
{
	parsing();
	return 0;
}