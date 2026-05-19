/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:29:06 by xalves            #+#    #+#             */
/*   Updated: 2025/04/23 18:57:22 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	char	s = 'C';
	ft_putchar_fd(s,1);
	return (0);
}*/
/*
if (fd < 0)
		return ;
	if (fd >= 0 && fd <= 2)
	{
		write(fd, &c, 1);
	}
*/
