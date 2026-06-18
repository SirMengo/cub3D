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

static void set_vars(int y, int x, t_map *map, char c)
{
	map->p_cardinal = c;
	map->x_pos = x;
	map->y_pos = y;
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
				return (print_error(MULT_PLR));
			else if(check_cardinal(map->map[y][x]))
			{
				set_vars(y, x, map, map->map[y][x]);
				flag = true;
			}
			x++;
		}
		y++;
	}
	if(!flag)
		return (print_error(NO_PLR));
	return (0);
}
