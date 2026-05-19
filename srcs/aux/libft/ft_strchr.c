/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:37:28 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 11:27:08 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*cc -Wall -Werror -Wextra ft_strchr.c
#include "libft.h"

int	main(void)
{
	char	s[] = "Banana";
	int	c = 'n';

	printf("In '%s' it found -> %s\n", s, ft_strchr(s,c));
	char	s1[] = "BaNaNa";
	printf("In '%s' it found -> %s\n", s1, ft_strchr(s1,c));
	char	s2[] = "abcdefghijklmnop";
	c = 'i';
	printf("In '%s' it found -> %s\n", s2, ft_strchr(s2,c));
	char	s3[] = "}{}{OSA}{}{{&*}}";
	c = 'O';
	printf("In '%s' it found -> %s\n", s3, ft_strchr(s3,c));
	char	s4[] = "";
	c = 'c';
	printf("In '%s' it found -> %s\n", s4, ft_strchr(s4,c));
	return (0);
} */
