/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:12:35 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 12:44:45 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (aux_s1[i] == '\0' && aux_s2[i] == '\0')
		{
			return (0);
		}
		if (aux_s1[i] == '\0' || aux_s2[i] == '\0')
		{
			return ((unsigned int)(aux_s1[i] - aux_s2[i]));
		}
		if (aux_s1[i] != aux_s2[i])
		{
			return ((unsigned int)(aux_s1[i] - aux_s2[i]));
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "Banana";
	char	s2[] = "Banana";
	int	n = 6;
	printf("Result %d \n",ft_strncmp("test\200", "test\0", 6));

	printf("First %d characters in:\nS1 = '%s' ", n, s1);
	printf("S2 = '%s' \nResult-> %d\n\n", s2, ft_strncmp(s1, s2, n));
	char	s3[] = "Banini";
	char	s4[] = "Banana";
	n = 3;

	printf("First %d characters in:\nS3 = '%s' ", n, s3);
	printf("S4 = '%s' \nResult-> %d\n\n", s4, ft_strncmp(s3, s4, n));

	char	s5[] = "Mango";
	char	s6[] = "Orange";
	printf("First %d characters in:\nS5 = '%s' ", n, s5);
	printf("S6 = '%s' \nResult-> %d\n\n", s6, ft_strncmp(s5, s6, n));
	return (0);
} */
