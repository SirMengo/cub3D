#ifndef PARSING_H
# define PARSING_H

//srcs/aux
# include "../aux/get_next_line/get_next_line.h"
# include "../aux/libft/libft.h"

//includes
# include <stdlib.h>
# include <stdio.h>
# include <curses.h>
# include <stdbool.h>

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
	int		north;
	int		south;
	int		west;
	int		east;
	int		ceiling;
	int		floor;

	//Map
	char	**map;
	int		row_count;
	int		width;

	//Player init
	char	p_cardinal;
	int		x_pos;
	int		y_pos;

	//File name
	char	*file_name;
	int		fd;
}	t_map;

//parsing.c
int		parsing(t_map **map);
//init_textures.c
int		get_texture(t_map *map, char *line);
//init_map.c
int		init_map(t_map *map);
//normalize_map.c
int		normalize_map(t_map *map);
//cleanup.c
void	free_map(t_map *map);
int		print_error(char *str);
//check_map.c
int		check_map(t_map *map);
//check_player.c
int		check_player(t_map *map);
//map_aux.c
int		is_valid_map_line(char *line);
int		ret_check(char *line, int fd);
void	replace_newline(char *line);
int		has_content(char *line);

//Error Messages
# define ALMAP_ERR "ERROR:\n Map struct allocation failed!\n"
# define ALFIL_ERR "ERROR:\n File name alocation failed!\n"
# define EX_ERR "ERROR:\n Invalid map extension! Must be \".cub\".\n"
# define FIL_EX "ERROR:\n File not existent or not readable.\n"
# define FIL_NAME "ERROR:\n File name or extension invalid.\n"
# define MAP_SIDES "ERROR:\n Invalid map borders.\n"
# define ST_MAPERR "ERROR:\n Map array alocation error.\n"
# define INV_COLOR "ERROR:\n Invalid color.\n"
# define NOR_ALLERR "ERROR:\n Failed alocation during map normalization.\n"
# define DBL_TEXTUR "ERROR:\n Double texture found.\n"
# define DBL_COLOR "ERROR:\n Double color found.\n"
# define NO_TEXTUR "ERROR:\n Missing texture.\n"
# define NO_COLOR "ERROR:\n Missing color.\n"
# define EXT_MAP "ERROR:\n Extra content after map.\n"
# define INV_CHAR "ERROR:\n Invalid character in map.\n"
# define NO_PLR "ERROR:\n No player found in map.\n"
# define MULT_PLR "ERROR:\n Multiple players found in map.\n"

#endif