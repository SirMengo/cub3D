/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:41:13 by xalves            #+#    #+#             */
/*   Updated: 2025/05/08 15:38:54 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	m;

	m = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (m / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/* int	main()
{
	char *s = ft_calloc(-1	, -1);

	s[0] = 'a';
	printf("%s", s);
} */
/*cc -Wall -Werror -Wextra ft_calloc.c ft_bzero.c
// int overflow check = (nmemb * size > 2147483647)
int	main(void)
{
	//alloc 5 int
	int	*numbers = (int *)ft_calloc(5, sizeof(int));
	// returns Null
	//int	*numbers = (int *)ft_calloc(0, sizeof(int));
	// returns Null
	//int	*numbers = (int *)ft_calloc(5,0);
	// returns Null
	//int	*numbers = (int *)ft_calloc(0,0);

	// Allocates 1Bil (danger test depends on pc)
	//int	*numbers = (int *)ft_calloc(1000000000,sizeof(int));

	if (numbers == NULL)
		printf("Could not callocate, returned NULL");
	else
	{
		printf("Callocate successfully");
		free(numbers);
	}
	return (0);
} */
