/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:05:10 by xalves            #+#    #+#             */
/*   Updated: 2025/04/30 13:02:56 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*aux_dest;
	const unsigned char	*aux_src;

	i = 0;
	if (!dest && !src)
		return (NULL);
	aux_dest = (unsigned char *)dest;
	aux_src = (unsigned char *)src;
	while (i < n)
	{
		aux_dest[i] = aux_src[i];
		i++;
	}
	return (dest);
}
/*cc -Wall -Werror -Wextra ft_memcpy.c
int	main(void)
{
	char	dest[20] = "Flint";
	char	src[20] = "Tutorials";

	printf("Dest before : %s\n", dest);
	ft_memcpy(dest,src, 20);
	printf("Dest after : %s\n", dest);
	return (0);
} */
