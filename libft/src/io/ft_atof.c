/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:29:39 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/08 13:12:17 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

static int	is_valid_float(const char *s)
{
	int	i;
	int	dot_count;
	int	digit_found;

	i = 0;
	dot_count = 0;
	digit_found = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			digit_found = 1;
		else if (s[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (digit_found);
}

static const char	*ft_parse_sign_and_integer(const char *s, int *sign,
		double *res)
{
	*sign = 1;
	*res = 0.0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sign = -1;
		else
			*sign = 1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		*res = *res * 10.0 + (*s - '0');
		s++;
	}
	return (s);
}

static double	ft_parse_fraction(const char *s)
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

	if (!is_valid_float(s))
		return (-1);
	s = ft_parse_sign_and_integer(s, &sign, &res);
	if (*s == '.' && s[1] >= '0' && s[1] <= '9')
		res += ft_parse_fraction(++s);
	return (res * sign);
}
