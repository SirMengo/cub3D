/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:26:15 by xalves            #+#    #+#             */
/*   Updated: 2025/04/14 09:34:11 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
#include "libft.h"

int	main(void)
{
	char	c = 'a';

	printf("'%c' tolower is -> %c\n", c, ft_tolower(c));
	c = 'A';
	printf("'%c' tolower is -> %c\n", c, ft_tolower(c));
	c = 'z';
	printf("'%c' tolower is -> %c\n", c, ft_tolower(c));
	c = 'Z';
	printf("'%c' tolower is -> %c\n", c, ft_tolower(c));
	c = '2';
	printf("'%c' tolower is -> %c\n", c, ft_tolower(c));
	c = '{';
	printf("'%c' tolower is -> %c\n", c, ft_tolower(c));
	c = ' ';
	printf("'%c' tolower is -> %c\n", c, ft_tolower(c));
	return (0);
} */
