/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:31:13 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 12:52:10 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*cc -Wall -Werror -Wextra ft_strrchr.c ft_strlen.c
int	main(void)
{
	char	s[] = "Banana";
	int	c = 'n';

	printf("In '%s' it found -> %s\n", s, ft_strrchr(s,c));
	char	s1[] = "BaNaNa";
	printf("In '%s' it found -> %s\n", s1, ft_strrchr(s1,c));

	char	s2[] = "Rinoceronte";
	c = 'n';
	printf("In '%s' it found -> %s\n", s2, ft_strrchr(s2,c));

	char	s3[] = "}{}{OSA}{}{{&*}}";
	c = '{';
	printf("In '%s' it found -> %s\n", s3, ft_strrchr(s3,c));

	char	s4[] = "";
	c = 'c';
	printf("In '%s' it found -> %s\n", s4, ft_strrchr(s4,c));
	return (0);
} */
