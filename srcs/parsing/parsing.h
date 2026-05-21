#ifndef PARSING_H
# define PARSING_H

# include "../aux/get_next_line/get_next_line.h"
# include "../aux/libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <curses.h>

typedef struct s_map
{
	//Texture/Color information:
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	char	*c_color;
	char	*f_color;

	//Check if loaded:
	bool	north;
	bool	south;
	bool	west;
	bool	east;
	bool	ceiling;
	bool	floor;

	char	**map;
}	t_map;

int get_texture(t_map *map, char *line);
int copy_map(t_map *map, char *line);

#endif