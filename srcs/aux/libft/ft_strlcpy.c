/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:48:26 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 12:28:30 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((char *)src);
	if (size == 0)
		return (len);
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*cc -Wall -Werror -Wextra ft_strlcpy.c ft_strlen.c
int	main(void)
{
	char	dst[13];
	char	*str = "Flint & Steel";

	// Copy the string
	size_t copied = ft_strlcpy(dst, str, 6); // 6 = lenght with the '\0'

	printf("To dst it copied: %s\n", dst);
	printf("Lenght of src: %zu\n\n", copied);

	copied = ft_strlcpy(dst, str, 14); // 14 = lenght with the '\0'
	printf("To dst it copied: %s\n", dst);
	printf("Lenght of src: %zu\n", copied);
	return (0);
} */
