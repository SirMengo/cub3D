/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:09:14 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 12:19:56 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= size)
		return (size + src_len);
	while (src[i] && (dst_len + i + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*cc -Wall -Werror -Wextra ft_strlcat.c ft_strlen.c
	//printf("src_len: %zu\n", src_len);
	//printf("dst_len: %zu\n", dst_len);
	//printf("size: %zu\n", size);

int	main(void)
{
	char dst[5] = "Hi ";
	char src[] = "there!";

	size_t len = ft_strlcat(dst, src, sizeof(dst));

	printf("Lenght Tried to copy %zu\n", len);
	printf("Result(size = %zu): '%s'\n\n", sizeof(dst), dst);


	char dst1[11] = "Hello ";
	char src1[] = "World!";

	len = ft_strlcat(dst1, src1, sizeof(dst1));

	printf("Lenght Tried to copy %zu\n", len);
	printf("Result(size = %zu): '%s'\n\n", sizeof(dst1), dst1);

	return (0);
} */
