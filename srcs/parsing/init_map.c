#include "parsing.h"

void replace_newline(char *line)
{
	size_t len;

	len = ft_strlen(line);
	if(len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int copy_map(t_map *map, char *line)
{
	int		row_count;
	char	**temp_map;
	int		i;

	row_count = 0;
	if (map->map)
		while(map->map[row_count])
			row_count++;
	temp_map = ft_calloc(row_count + 2, sizeof(char *));
	if (!temp_map)
		return (1);
	i = 0;
	while (i < row_count)
	{
		temp_map[i] = map->map[i];
		i++;
	}
	replace_newline(line);
	temp_map[row_count] = ft_substr(line, 0, ft_strlen(line));
	if(!temp_map[row_count])
		return (free(temp_map), 1);
	temp_map[row_count + 1] = NULL;
	free(map->map);
	map->map = temp_map;
	return (0);
}
