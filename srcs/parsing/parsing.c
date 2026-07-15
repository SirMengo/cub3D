#include "parsing.h"

static int	check_filename(t_map *map)
{
	int	len;

	len = ft_strlen(map->file_name);
	if (len <= 4)
		return (print_error(FIL_NAME));
	if (map->file_name[len - 1] != 'b')
		return (print_error(FIL_NAME));
	if (map->file_name[len - 2] != 'u')
		return (print_error(FIL_NAME));
	if (map->file_name[len - 3] != 'c')
		return (print_error(FIL_NAME));
	if (map->file_name[len - 4] != '.')
		return (print_error(FIL_NAME));
	if (map->file_name[len - 5] == '/')
		return (print_error(FIL_NAME));
	return (0);
}

static int	check_number_textures(t_map *map)
{
	if (map->north < 1)
		return (print_error(NO_TEXTUR));
	if (map->south < 1)
		return (print_error(NO_TEXTUR));
	if (map->west < 1)
		return (print_error(NO_TEXTUR));
	if (map->east < 1)
		return (print_error(NO_TEXTUR));
	if (map->ceiling < 1)
		return (print_error(NO_COLOR));
	if (map->floor < 1)
		return (print_error(NO_COLOR));
	if (map->north != 1)
		return (print_error(DBL_TEXTUR));
	if (map->south != 1)
		return (print_error(DBL_TEXTUR));
	if (map->west != 1)
		return (print_error(DBL_TEXTUR));
	if (map->east != 1)
		return (print_error(DBL_TEXTUR));
	if (map->ceiling != 1)
		return (print_error(DBL_COLOR));
	if (map->floor != 1)
		return (print_error(DBL_COLOR));
	return (0);
}

int	parsing(t_map **map, char *filename)
{
	*map = ft_calloc(1, sizeof(t_map));
	if (!*map)
		return (free_map(*map), print_error(ALMAP_ERR));
	(*map)->file_name = ft_strdup(filename);
	if (!(*map)->file_name)
		return (free_map(*map), print_error(ALFIL_ERR));
	if (check_filename(*map))
		return (free_map(*map), 1);
	if (init_map(*map))
		return (free_map(*map), 1);
	if (check_number_textures(*map))
		return (free_map(*map), 1);
	if (check_map(*map))
		return (free_map(*map), 1);
	if (check_player(*map))
		return (free_map(*map), 1);
	return (0);
}
