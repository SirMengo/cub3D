/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:15:52 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 10:47:40 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)str;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*cc -Wall -Werror -Wextra ft_bzero.c
// Entre a linha 23 e 24 	printf("%c\n", ptr[i]);
int	main(void)
{
	char	str[20] = "Welcome to Jumanji";
	int	i = 0;
	printf("%s\n", str);
	ft_bzero(str, 7);
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
	return (0);
} */
