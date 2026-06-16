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
		return (print_error(ST_MAPERR));
	i = 0;
	while (i < map->row_count)
	{
		temp_map[i] = map->map[i];
		i++;
	}
	replace_newline(line);
	temp_map[map->row_count] = ft_substr(line, 0, ft_strlen(line));
	if(!temp_map[map->row_count])
		return (free(temp_map), print_error(ST_MAPERR));
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

static int ret_check(char *line, int fd)
{
	while((line = get_next_line(fd)) != NULL)
		free(line);
	return (close(fd), 1);
}

int init_map(t_map *map)
{
	char	*line;
	int		fd;
	int		ret;

	if (access(map->file_name, R_OK))
		return (print_error(FIL_EX));
	fd = open(map->file_name, O_RDONLY);
	if (fd < 0)
		return (print_error(FIL_EX));
	ret = 0;
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
		if (ret)
			return (ret_check(NULL, fd));
	}
	close (fd);
	return (normalize_map(map));
}
