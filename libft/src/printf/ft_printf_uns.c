/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:29:42 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_len(unsigned int num)
{
	int	len;

	len = 1;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*ft_utoa(unsigned int num)
{
	char	*str;
	int		len;

	len = ft_unsigned_len(num);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

int	ft_putunsigned(unsigned int num, int fd)
{
	char	*str;
	int		len;

	str = ft_utoa(num);
	if (!str)
		return (-1);
	len = ft_putstr(str, fd);
	free(str);
	return (len);
}

int	ft_putptr(void *ptr, int fd)
{
	char	*hex;
	int		len;
	int		hex_len;

	if (!ptr)
		return (ft_putstr("(nil)", fd));
	len = ft_putstr("0x", fd);
	if (len == -1)
		return (-1);
	hex = ft_itoa_hex((uintptr_t)ptr, "0123456789abcdef");
	if (!hex)
		return (-1);
	if (len >= 0)
	{
		hex_len = ft_putstr(hex, fd);
		if (hex_len == -1)
			len = -1;
		else
			len += hex_len;
	}
	free(hex);
	return (len);
}
