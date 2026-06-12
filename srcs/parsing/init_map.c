#include "parsing.h"

static void replace_newline(char *line)
{
	size_t len;

	len = ft_strlen(line);
	if(len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static int copy_map(t_map *map, char *line)
{
	char	**temp_map;
	int		i;

	map->row_count = 0;
	if (map->map)
		while(map->map[map->row_count])
			map->row_count++;
	temp_map = ft_calloc(map->row_count + 2, sizeof(char *));
	if (!temp_map)
		return (1);
	i = 0;
	while (i < map->row_count)
	{
		temp_map[i] = map->map[i];
		i++;
	}
	replace_newline(line);
	temp_map[map->row_count] = ft_substr(line, 0, ft_strlen(line));
	if(!temp_map[map->row_count])
		return (free(temp_map), 1);
	temp_map[map->row_count + 1] = NULL;
	free(map->map);
	map->map = temp_map;
	return (0);
}

static int has_content(char *line)
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
	int		fd;
	int		ret;

	if (access("file.txt", R_OK))
		return (1);
	fd = open("file.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!has_content(line))
		{
			free(line);
			continue ;
		}
		if (map->north && map->south && map->west && map->east && map->floor && map->ceiling)
			ret = copy_map(map, line);
		else
			ret = get_texture(map, line);
		free(line);
	}
	if(ret)
		return (close(fd), 1);
	close (fd);
	return (normalize_map(map));
}
