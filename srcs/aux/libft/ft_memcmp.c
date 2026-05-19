/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:08:09 by xalves            #+#    #+#             */
/*   Updated: 2025/04/29 18:55:25 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (aux_s1[i] != aux_s2[i])
		{
			return ((unsigned int)(aux_s1[i] - aux_s2[i]));
		}
		i++;
	}
	return (0);
}
/*cc -Wall -Werror -Wextra ft_memcmp.c
 int	main(void)
{
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	printf("memcmp = %d\n",ft_memcmp(s2, s3, 4));
	return (0);
}
 */
/*
#include <string.h>
int	main(void)
{
	char a[] = "hello";
	char b[] = "hello";
	int res = ft_memcmp(a, b, 5);

	printf("| %s && %s | -> %d\n", a, b, res);
	printf("OG| %s && %s | -> %d", a, b, memcmp(a, b, 5));

	char c[] = "hello";
	char d[] = "heLlo";
	res = ft_memcmp(c, d, 5);

	printf("\n\n| %s && %s | -> %d\n", c, d, res);
	printf("OG| %s && %s | -> %d", c, d, memcmp(c, d, 5));

	char e[] = "abcdef";
	char f[] = "abcxyz";
	res = ft_memcmp(e, f, 3);

	printf("\n\n| %s && %s | -> %d\n", e, f, res);
	printf("OG| %s && %s | -> %d", e, f, memcmp(e, f, 3));

	return (0);
} */
