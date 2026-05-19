/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:30:30 by xalves            #+#    #+#             */
/*   Updated: 2025/04/30 13:06:53 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*aux_dest;
	const unsigned char	*aux_src;

	i = 0;
	if (!dest && !src)
		return (NULL);
	aux_dest = (unsigned char *)dest;
	aux_src = (unsigned char *)src;
	if (aux_dest > aux_src)
	{
		i = n;
		while (i-- > 0)
			aux_dest[i] = aux_src[i];
	}
	else
	{
		i = -1;
		while (++i < n)
			aux_dest[i] = aux_src[i];
	}
	return (dest);
}
/* //cc -Wall -Werror -Wextra ft_memmove.c
int	main(void)
{
	char	dest[20] = "Cadabra";
	char	src[20] = "Banana";
	int		n = 5;

	printf("OG function : %p\n",memmove(NULL,NULL,5));
	printf("Dest Before: %s\n", dest);
	ft_memmove(dest,src, n);
	printf("Dest After: %s\n\n", dest);

	char	dest1[20] = "Banana";
	char	src1[20] = "Cadabra";
	n = 7;

	printf("Dest1 Before: %s\n", dest1);
	ft_memmove(dest1,src1, n);
	printf("Dest1 After: %s\n\n", dest1);
	return (0);
} */
