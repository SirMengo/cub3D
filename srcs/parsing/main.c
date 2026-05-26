#include "parsing.c"

int main()
{
	t_map	*map;
	parsing(&map);

	printf("TESTES\n");
	printf("TEXTURAS & CORES:\n");
	printf("NORTH: %s\n", map->n_texture);
	printf("SOUTH: %s\n", map->s_texture);
	printf("EAST: %s\n", map->e_texture);
	printf("WEST: %s\n", map->w_texture);
	printf("FLOOR: %s\n", map->f_color);
	printf("CIEILING: %s\n\n", map->c_color);

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
