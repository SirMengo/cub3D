/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:01:48 by msimoes           #+#    #+#             */
/*   Updated: 2025/05/08 15:27:09 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (reset_buffer(buffer))
			break ;
	}
	return (line);
}

/*
int main()
{
	char *gnl_fd;
	int fd = open("test.txt", O_RDONLY | O_CREAT);
	
	while ((gnl_fd = get_next_line(fd)) != NULL)
	{
		printf("%s", gnl_fd);
		free(gnl_fd);	
	}
	printf("\n");
	close(fd);
}
*/
