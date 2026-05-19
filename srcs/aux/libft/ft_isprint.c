/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:16:52 by xalves            #+#    #+#             */
/*   Updated: 2025/04/23 11:12:29 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int arg)
{
	if (arg >= 32 && arg < 127)
		return (arg);
	else
		return (0);
}
/*
#include "libft.h"

int	main(void)
{
	char	c = 'a';

	int i = 123;
	while (i <= 127)
	{
		printf("%d \n", ft_isprint(i));
		i++;
	}
	printf("%c Returned Value is -> %d\n", c, ft_isprint(c));
	c = 'A';
	printf("%c Returned Value is -> %d\n", c, ft_isprint(c));
	c = '{';
	printf("%c Returned Value is -> %d\n", c, ft_isprint(c));
	c = '@';
	printf("%c Returned Value is -> %d\n", c, ft_isprint(c));

	int	 n = 0;
	printf("%c Returned Value is -> %d\n", n, ft_isprint(n));
	n = 7;
	printf("%c Returned Value is -> %d\n", n, ft_isprint(n));
	n = 31;
	printf("%c Returned Value is -> %d\n", n, ft_isprint(n));
	return (0);
} */
