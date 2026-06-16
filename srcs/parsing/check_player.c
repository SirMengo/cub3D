#include "parsing.h"

static int check_cardinal(char c)
{
	if(c == 'E')
		return (1);
	if(c == 'W')
		return (1);
	if(c == 'S')
		return (1);
	if(c == 'N')
		return (1);
	return (0);
}

int check_player(t_map *map)
{
	int		x;
	int		y;
	bool	flag;

	y = 0;
	flag = false;
	while(map->map[y])
	{
		x = 0;
		while(map->map[y][x])
		{
			if(check_cardinal(map->map[y][x]) && flag == true)
				return (1);
			else if(check_cardinal(map->map[y][x]))
			{
				map->p_cardinal = map->map[y][x];
				map->x_pos = x;
				map->y_pos = y;
				flag = true;
			}
			x++;
		}
		y++;
	}
	return (0);
}
