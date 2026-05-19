/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:38:12 by xalves            #+#    #+#             */
/*   Updated: 2025/05/14 12:39:53 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	new_str = ft_calloc(s1_len + s2_len + 1, sizeof(char)); // calloc instead of malloc
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < s1_len && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len && s2[i])
	{
		new_str[s1_len + i] = s2[i];
		i++;
	}
	return (new_str);
}
/*cc -Wall -Werror -Wextra ft_strjoin.c ft_strlen.c
int	main(void)
{
	char	s1[] = "Flint &";
	char	s2[] = "& Steel";
	char	*join = ft_strjoin(s1,s2);
	if(join != NULL)
	{
		printf("Join = %s\n",join);
		printf("Join len (+ null bit) = %lu\n",ft_strlen(join)+1);
		free(join);
	}
	else
		printf("Encontered a NULL");
	return (0);
} */
