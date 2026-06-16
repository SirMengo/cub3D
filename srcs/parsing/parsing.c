#include "parsing.h"

static int check_filename(t_map *map)
{
	int len;

	len = ft_strlen(map->file_name);
	if(map->file_name[len - 1] != 'b')
		return (1);
	if(map->file_name[len - 2] != 'u')
		return (1);
	if(map->file_name[len - 3] != 'c')
		return (1);
	if(map->file_name[len - 4] != '.')
		return (1);
	return (0);
}

int parsing(t_map **map)
{
	*map = ft_calloc(1, sizeof(t_map));
	if(!*map)
		return (free_map(*map), print_error(ALMAP_ERR));
	(*map)->file_name = ft_strdup("file.cub");
	if(!(*map)->file_name)
		return (free_map(*map), print_error(ALFIL_ERR));
	if(check_filename(*map))
		return (free_map(*map), print_error(EX_ERR));
	if(init_map(*map))
		return (free_map(*map), 1);
	if(check_map(*map))
		return (free_map(*map), 1);
	return (0);
}
