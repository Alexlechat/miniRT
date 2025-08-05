/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:44:32 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str, int fd)
{
	if (!str)
	{
		if (write(fd, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	if (write(fd, str, ft_strlen(str)) == -1)
		return (-1);
	return (ft_strlen(str));
}

int	ft_putnbr(long n, int fd)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	if (!num)
		return (-1);
	len = ft_putstr(num, fd);
	free(num);
	return (len);
}
