#include "parsing.h"

int is_valid_map_line(char *line)
{
	int i;
	int has_map_char = 0;
	char c;

	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c == '0' || c == '1' || c == 'N' || c == 'S' ||
			c == 'E' || c == 'W')
			has_map_char = 1;
		else if (c != ' ' && c != '\t')
			return (0);
		i++;
	}
	return (has_map_char);
}
