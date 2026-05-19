/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:55:51 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 10:47:58 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	if (ft_isalpha(arg) || ft_isdigit(arg))
		return (arg);
	return (0);
}
/*cc -Wall -Werror -Wextra ft_isalnum.c ft_isalpha.c ft_isdigit.c
int	main(void)
{
	char	c = 'a';

	printf("%c Returned Value is -> %d\n", c, ft_isalnum(c));
	c = '3';
	printf("%c Returned Value is -> %d\n", c, ft_isalnum(c));
	c = ';';
	printf("%c Returned Value is -> %d\n", c, ft_isalnum(c));
	c = '@';
	printf("%c Returned Value is -> %d\n", c, ft_isalnum(c));
	return (0);
} */
