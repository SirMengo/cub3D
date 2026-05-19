/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:29:37 by xalves            #+#    #+#             */
/*   Updated: 2025/04/30 10:27:26 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n)
	{
		n /= 10;
		++count;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str_itoa;
	int		len;

	len = count_digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str_itoa = malloc(sizeof(char) * (len + 1));
	if (!str_itoa)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str_itoa[0] = '-';
	}
	if (n == 0)
		str_itoa[0] = '0';
	str_itoa[len] = '\0';
	while (n)
	{
		str_itoa[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str_itoa);
}
/*
// Make sure your ft_itoa and ft_strdup are defined or included here

void run_test(int n, const char *expected)
{
	char *result = ft_itoa(n);
	if (!result)
	{
		printf("ft_itoa(%d) = NULL (expected: %s)\n", n, expected);
		return;
	}

	if (strcmp(result, expected) == 0)
		printf("✅ ft_itoa(%d) = \"%s\"\n", n, result);
	else
		printf("❌ ft_itoa(%d) = \"%s\" (expected: \"%s\")\n", n, result, expected);

	free(result);
}

int main(void)
{
	run_test(7, "7");
	run_test(-3, "-3");
	run_test(1000, "1000");
	run_test(-1000, "-1000");
	run_test(999, "999");
	run_test(-999, "-999");
	run_test(2147483646, "2147483646");
	run_test(-2147483647, "-2147483647");
	run_test(0, "0");
	run_test(12345, "12345");
	run_test(-9876, "-9876");
	run_test(INT_MAX, "2147483647");
	run_test(INT_MIN, "-2147483648");

	return 0;
} */
