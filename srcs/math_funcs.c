/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:42:53 by xalves            #+#    #+#             */
/*   Updated: 2026/08/04 16:44:17 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	hex_to_int(const char *hex)
{
	int	result;
	int	value;

	result = 0;
	while (*hex)
	{
		if (*hex >= '0' && *hex <= '9')
			value = *hex - '0';
		else if (*hex >= 'A' && *hex <= 'F')
			value = *hex - 'A' + 10;
		else if (*hex >= 'a' && *hex <= 'f')
			value = *hex - 'a' + 10;
		else
			return (-1);
		result = result * 16 + value;
		hex++;
	}
	return (result);
}

float	normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

double	degrees_to_radians(double degrees)
{
	return (degrees * PI / 180.0);
}

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}
