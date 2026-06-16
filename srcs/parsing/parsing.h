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
	char	*file_name;

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
int print_error(char *str);
//checl_map.c
int check_map(t_map *map);

//Error Messages
#define ALMAP_ERR "ERROR:\n Map struct allocation failed!\n"
#define ALFIL_ERR "ERROR:\n File name alocation failed!\n"
#define EX_ERR "ERROR:\n Invalid map extension! Must be \".cub\".\n"
#define FIL_EX "ERROR:\n File not existent or not readable.\n"
#define MAP_SIDES "ERROR:\n Invalid map borders.\n"
#define ST_MAPERR "ERROR:\n Map array alocation error.\n"
#define INV_COLOR "ERROR:\n Invalid color.\n"
#define NOR_ALLERR "ERROR:\n Failed alocation during map normalization.\n"
#endif