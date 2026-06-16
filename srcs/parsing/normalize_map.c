#include "parsing.h"

static size_t get_max_width(char **map)
{
	size_t	max;
	size_t	len;
	int		i;

	max = 0;
	i = 0;
	while(map[i])
	{
		len = ft_strlen(map[i]);
		if(len > max)
			max = len;
		i++;
	}
	return (max);
}

int normalize_map(t_map *map)
{
	int		row_len;
	char	*normalize;
	int		i;

	if(!map->map)
		return (1);
	map->width = get_max_width(map->map);
	i = 0;
	while(map->map[i])
	{
		row_len = ft_strlen(map->map[i]);
		if(row_len < map->width)
		{
			normalize = ft_calloc(map->width + 1, sizeof(char));
			if(!normalize)
				return (print_error(NOR_ALLERR));
			ft_memcpy(normalize, map->map[i], row_len);
			ft_memset(normalize + row_len, ' ', map->width - row_len);
			normalize[map->width] = '\0';
			free(map->map[i]);
			map->map[i] = normalize;
		}
		i++;
	}
	return (0);
}
