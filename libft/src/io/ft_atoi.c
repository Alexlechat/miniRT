/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:59:13 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/08 13:10:52 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while ((str[i]))
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result > INT_MAX)
		return (-1);
	return ((int)result);
}
