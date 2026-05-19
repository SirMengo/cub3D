/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:13:24 by xalves            #+#    #+#             */
/*   Updated: 2025/04/14 09:25:36 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
#include "libft.h"

int	main(void)
{
	char	c = 'a';

	printf("'%c' toupper is -> %c\n", c, ft_toupper(c));
	c = 'A';
	printf("'%c' toupper is -> %c\n", c, ft_toupper(c));
	c = 'z';
	printf("'%c' toupper is -> %c\n", c, ft_toupper(c));
	c = 'Z';
	printf("'%c' toupper is -> %c\n", c, ft_toupper(c));
	c = '2';
	printf("'%c' toupper is -> %c\n", c, ft_toupper(c));
	c = '{';
	printf("'%c' toupper is -> %c\n", c, ft_toupper(c));
	c = ' ';
	printf("'%c' toupper is -> %c\n", c, ft_toupper(c));
	return (0);
} */
