/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:17:56 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 12:41:44 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	f(unsigned int i, char s)
{
	(void)i;
	return (ft_toupper(s));
} */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	s_len = ft_strlen((char *)s);
	new_str = malloc(sizeof(char) * (s_len + 1));
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[s_len] = '\0';
	return (new_str);
}
/*
int	main(void)
{
	char	s[] = "Flint and Steel";
	char	*mapi = ft_strmapi(s,f);
	if(mapi != NULL)
	{
		printf("Join = %s\n",mapi);
		free(mapi);
	}
	else
		printf("Encontered a NULL");
	return (0);
} */
