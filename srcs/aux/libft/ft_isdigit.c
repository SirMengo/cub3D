/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:32:12 by xalves            #+#    #+#             */
/*   Updated: 2025/04/11 12:11:44 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int d)
{
	if (d >= 48 && d <= 57)
		return (d);
	else
		return (0);
}
/*
#include "libft.h"

int	main(void)
{
	char	d = '0';

	printf("%c Returned Value is -> %d\n", d, ft_isdigit(d));
	d = '9';
	printf("%c Returned Value is -> %d\n", d, ft_isdigit(d));
	d = '{';
	printf("%c Returned Value is -> %d\n", d, ft_isdigit(d));
	d = ';';
	printf("%c Returned Value is -> %d\n", d, ft_isdigit(d));
	return (0);
} */
