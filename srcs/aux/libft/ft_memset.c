/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:43:46 by xalves            #+#    #+#             */
/*   Updated: 2025/04/30 10:40:44 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)str;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (str);
}
/*cc -Wall -Werror -Wextra ft_memset.c
int	main(void)
{
	char	str[20] = "Welcome to Jumanji";

	printf("%s\n", str);
	ft_memset(str, '?', 7);
	printf("%s\n", str);
	return (0);
} */
