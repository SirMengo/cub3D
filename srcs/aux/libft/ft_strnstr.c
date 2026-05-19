/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:38:08 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 12:50:21 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lit_len;

	i = 0;
	lit_len = ft_strlen((char *)little);
	if (lit_len == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j] && i < len)
		{
			while (little[j] != '\0' && big[i + j] == little[j])
			{
				if ((i + j) == len)
					break ;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/* int	main(void)
{
	char	*str;
	if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15)))
		printf("NULL\n");
	else
		printf("str = %s\n", str);
	return (0);
} */
/*cc -Wall -Werror -Wextra ft_strnstr.c ft_strlen.c
// Line 31-32 	printf("%c | %c \n",big[i], little[j]);
int main(void)
{
	char	big[] = "aaaddavidaaa";
	char	little[] = "david";

	printf("Output -> %s\n\n", ft_strnstr(big, little, 6));

	// returns "world"
	printf("Output -> %s\n\n", ft_strnstr("hello world", "world", 11));

	// returns NULL
	printf("Output -> %s\n\n", ft_strnstr("hello world", "world", 5));

	// returns "hello"
	printf("Output -> %s\n\n", ft_strnstr("hello", "", 5));

	// returns NULL
	printf("Output -> %s\n\n", ft_strnstr("hi", "hello", 5));

	// returns "e"
	printf("Output -> %s\n\n", ft_strnstr("abcde", "e", 5));

	return (0);
} */
