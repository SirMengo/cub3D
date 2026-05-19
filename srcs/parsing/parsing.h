#ifndef PARSING_H
# define PARSING_H

# include "../aux/get_next_line/get_next_line.h"
# include "../aux/libft/libft.h"

# include <stdlib.h>
# include <stdio.h>

typedef struct s_map
{
	char *n_texture;
	char *s_texture;
	char *w_texture;
	char *e_texture;
	char *floor;
	char *cieling;
	char *map;
}	t_map;

#endif