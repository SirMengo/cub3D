/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:30:14 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 10:53:15 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*aux_s;

	i = 0;
	aux_s = (unsigned char *)s;
	while (i < n)
	{
		if (aux_s[i] == (unsigned char )c)
			return (&aux_s[i]);
		i++;
	}
	return (NULL);
}
/*cc -Wall -Werror -Wextra ft_memchr.c ft_strlen.c
void	reply(char* s, int c, char* resp)
{
	if (resp != NULL)
		printf("Found '%c' at position: %zu\n\n", c, (size_t)(resp - s));
	else
		printf("'%c' not found.\n\n",c);
}
int	main(void)
{
	char s[] = "banana";
	int c = 'n';
	char *resp = ft_memchr(s, c, ft_strlen(s));

	printf("resp = %zu | s = %zu\n", (size_t)resp, (size_t)s);
	reply( s, c, resp);

	char s1[] = "hello world";
	int c1 = 'o';
	char *resp1 = ft_memchr(s1, c1, ft_strlen(s1));

	printf("\n\nresp = %zu | s = %zu\n", (size_t)resp1, (size_t)s1);
	reply( s1, c1, resp1);

	char s2[] = "Mango";
	int c2 = 'M';
	char *resp2 = ft_memchr(s2, c2, ft_strlen(s2));

	printf("\n\nresp = %zu | s = %zu\n", (size_t)resp2, (size_t)s2);
	reply( s2, c2, resp2);

	return (0);
} */
