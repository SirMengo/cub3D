/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:22:57 by xalves            #+#    #+#             */
/*   Updated: 2026/07/22 19:22:59 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_valid_map_line(char *line)
{
	int		i;
	int		has_map_char;
	char	c;

	i = 0;
	has_map_char = 0;
	while (line[i])
	{
		c = line[i];
		if (c == '0' || c == '1' || c == 'N' || c == 'S'
			|| c == 'E' || c == 'W')
			has_map_char = 1;
		else if (c != ' ' && c != '\t')
			return (0);
		i++;
	}
	return (has_map_char);
}

int	ret_check(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	replace_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	has_content(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
