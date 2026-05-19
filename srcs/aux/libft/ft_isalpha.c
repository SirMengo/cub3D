/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:41:52 by xalves            #+#    #+#             */
/*   Updated: 2025/04/11 12:11:32 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (c);
	else
		return (0);
}
/*
#include "libft.h"

int	main(void)
{
	char	c = 'a';

	printf("%c Returned Value is -> %d\n", c, ft_isalpha(c));
	c = 'A';
	printf("%c Returned Value is -> %d\n", c, ft_isalpha(c));
	c = '{';
	printf("%c Returned Value is -> %d\n", c, ft_isalpha(c));
	c = '@';
	printf("%c Returned Value is -> %d\n", c, ft_isalpha(c));
	return (0);
} */
