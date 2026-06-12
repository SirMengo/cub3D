#include "parsing.h"

static int is_whitespace(char c)
{
	if(c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int check_sides()

int check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if(i == 0 || i == map->row_count)
				if(map->map[i][j] != '1')
					return (1);
			else
			{
			}
			j++;
		}
	}

}
