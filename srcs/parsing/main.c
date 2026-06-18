#include "parsing.c"

int main()
{
	t_map	*map;
	if(parsing(&map))
		return (1);

	printf("TESTES\n");
	printf("TEXTURAS & CORES:\n");
	printf("NORTH: %s\n", map->n_texture);
	printf("SOUTH: %s\n", map->s_texture);
	printf("EAST: %s\n", map->e_texture);
	printf("WEST: %s\n", map->w_texture);
	printf("RGB: %d %d %d\n", map->f_rgb[0], map->f_rgb[1], map->f_rgb[2]);
	printf("FLOOR: #%s\n", map->hex_floor);
	printf("CEILING: #%s\n", map->hex_cieling);
	printf("////////////////////////////////////////\n");
	printf("PLAYER X: %i\n", map->x_pos);
	printf("PLAYER Y: %i\n", map->y_pos);
	printf("PLAYER CARDINAL: %c\n", map->p_cardinal);

	int i = 0;
	printf("MAPA:\n");
	while(map->map[i])
	{
		printf("%s\\0\n", map->map[i]);
		i++;
	}
	free_map(map);
	return 0;
}
