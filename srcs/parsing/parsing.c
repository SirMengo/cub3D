#include "parsing.h"

int parsing(t_map **map)
{
	*map = ft_calloc(1, sizeof(t_map));
	if(!*map)
		return (1);
	if (init_map(*map))
		return(free_map(*map), 1);
	if(check_map(*map) == 0)
		printf("Parsing passed\n");
	else
		printf("Parsing failed\n");
	return (0);
}
