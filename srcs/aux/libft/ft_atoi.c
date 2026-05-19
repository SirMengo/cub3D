/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:42:16 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 10:47:17 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}
/*cc -Wall -Werror -Wextra ft_atoi.c
int	main(void)
{
	char	nptr[] = "+1234ab567";
	int	result = ft_atoi(nptr);

	// returns 1234
	printf("The resulting Int is = %d \n", result);
	// returns 42
	printf("The resulting Int is = %d \n", ft_atoi("42"));
	// returns -42
	printf("The resulting Int is = %d \n", ft_atoi("   -42"));
	// returns 123
	printf("The resulting Int is = %d \n", ft_atoi("\t  123"));
	// returns 0 (starts with letters)
	printf("The resulting Int is = %d \n", ft_atoi("words 123"));
	// returns 0
	printf("The resulting Int is = %d \n", ft_atoi(""));


	//Testing int limits

	// returns 2147483647 (max value of int )
	printf("The resulting Int is = %d \n", ft_atoi("2147483647"));
	// returns overflow
	printf("The resulting Int is = %d \n", ft_atoi("2147483648"));

	// returns -2147483648 (min value of int)
	printf("The resulting Int is = %d \n", ft_atoi("-2147483648"));
	// returns overflow
	printf("The resulting Int is = %d \n", ft_atoi("-2147483649"));

	return (0);
} */
