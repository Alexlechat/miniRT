/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:29:39 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/07 11:32:37 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

static double	ft_frac(const char *s)
{
	double	f;
	int		i;

	f = 0.0;
	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		f = f * 10.0 + (s[i] - '0');
		i++;
	}
	return (f / pow(10, i));
}

double	ft_atof(const char *s)
{
	double	res;
	int		sign;

	res = 0.0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
		sign = (*s++ == '-') ? -1 : 1;
	while (*s >= '0' && *s <= '9')
		res = res * 10.0 + (*s++ - '0');
	if (*s == '.' && s[1] >= '0' && s[1] <= '9')
		res += ft_frac(++s);
	return (res * sign);
}
