/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:33:03 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 12:52:26 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str_trim;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen((char *)s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	str_trim = malloc(sizeof(char) * (end - start + 1));
	if (!str_trim)
		return (NULL);
	ft_strncpy(str_trim, (char *)s1 + start, end - start);
	str_trim[end - start] = '\0';
	return (str_trim);
}
/*
int	main(void)
{
	char	s1[] = "dsidsiFLINT && STEELisdisds";
	char	set[] = "dis";
	char	*trim = ft_strtrim(s1,set);

	if(trim != NULL)
	{
		printf("Join = %s\n",trim);
		printf("Join len (+ null bit) = %d\n",ft_strlen(trim)+1);
		free(trim);
	}
	else
		printf("Encontered a NULL");

	printf("1: '%s'\n", ft_strtrim("   Banana   ", " "));
	printf("2: '%s'\n", ft_strtrim("\n\t hello \t\n", " \n\t"));
	printf("3: '%s'\n", ft_strtrim("xxxyChickenxyx", "xy"));
	printf("4: '%s'\n", ft_strtrim("hello", "xyz"));
	printf("5: '%s'\n", ft_strtrim("xxxx", "x"));
	printf("6: '%s'\n", ft_strtrim("100%% Null", NULL));
	return (0);
} */
