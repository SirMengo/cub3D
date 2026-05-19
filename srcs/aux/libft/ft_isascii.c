/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:42:37 by xalves            #+#    #+#             */
/*   Updated: 2025/04/23 11:04:34 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include "libft.h"

int	main(void)
{
	char	c = 'a';

	printf("%c Returned Value is -> %d\n", c, ft_isascii(c));
	c = 'A';
	printf("%c Returned Value is -> %d\n", c, ft_isascii(c));
	c = '{';
	printf("%c Returned Value is -> %d\n", c, ft_isascii(c));
	c = '@';
	printf("%c Returned Value is -> %d\n", c, ft_isascii(c));

	int	 n = 128;
	printf("%c Returned Value is -> %d\n", n, ft_isascii(n));
	n = 140;
	printf("%c Returned Value is -> %d\n", n, ft_isascii(n));
	n = 250;
	printf("%c Returned Value is -> %d\n", n, ft_isascii(n));
	return (0);
} */
