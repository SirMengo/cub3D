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

int ret_check(char *line, int fd)
{
	while((line = get_next_line(fd)) != NULL)
		free(line);
	return (close(fd), 1);
}

void replace_newline(char *line)
{
	size_t len;

	len = ft_strlen(line);
	if(len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int has_content(char *line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if(line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
