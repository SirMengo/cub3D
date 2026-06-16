#ifndef PARSING_H
# define PARSING_H

//srcs/aux
# include "../aux/get_next_line/get_next_line.h"
# include "../aux/libft/libft.h"

//includes
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
	int		c_rgb[3];
	int		f_rgb[3];
	char	*hex_cieling;
	char	*hex_floor;

	//Check if loaded:
	bool	north;
	bool	south;
	bool	west;
	bool	east;
	bool	ceiling;
	bool	floor;

	//Map
	char	**map;
	int		row_count;

	//Player init
	char	*p_cardinal;
	char	*x_pos;
	char	*y_pos;

}	t_map;

//parsing.c
int parsing(t_map **map);
//init_textures.c
int get_texture(t_map *map, char *line);
//init_map.c
int init_map(t_map *map);
//normalize_map.c
int normalize_map(t_map *map);
//cleanup.c
void free_map(t_map *map);
//checl_map.c
int check_map(t_map *map);

#endif