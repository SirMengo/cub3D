/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:52:46 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 12:58:20 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub_str;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len >= s_len - start)
		len = (s_len - start);
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
/*cc -Wall -Werror -Wextra ft_substr.c ft_strlen.c ft_strdup.c
int	main(void)
{
	char	s[] = "Banana";
	char	*copy = ft_substr(s,2,3);
	if(copy != NULL)
	{
		printf("OG = %s | Copy = %s\n",s,copy);
		printf("OG len = %lu |",ft_strlen(s) + 1);
		printf(" Copy len = %lu\n",ft_strlen(copy) + 1);
		free(copy);
	}
	else
		printf("Encontered a NULL");
	return (0);
} */
