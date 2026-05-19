/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:04:34 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 11:56:12 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	f(unsigned int i, char* s)
{
	(void)i;
	*s = ft_toupper(*s);
} */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*cc -Wall -Werror -Wextra ft_striteri.c ft_toupper.c
int	main(void)
{
	char	s[] = "Flint and Steel";
	ft_striteri(s,f);
	printf("Join = %s\n",s);
	return (0);
} */
