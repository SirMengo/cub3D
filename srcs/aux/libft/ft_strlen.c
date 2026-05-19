/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:26:09 by xalves            #+#    #+#             */
/*   Updated: 2025/04/30 10:16:18 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	char	str[] = "Banana";

	const char *s = "aaaaa";
	printf("'%s' Size is -> %d\n", s, ft_strlen(s));
	 printf("'%s' Size is -> %d\n", str, ft_strlen(str));
	char	str1[] = "7DeSize";
	printf("'%s' Size is -> %d\n", str1, ft_strlen(str1));
	char	str2[] = "123456789";
	printf("'%s' Size is -> %d\n", str2, ft_strlen(str2));
	char	str3[] = "";
	printf("'%s' Size is -> %d\n", str3, ft_strlen(str3));

	return (0);
}*/
