/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:08:36 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(uintptr_t num)
{
	int	len;

	len = 1;
	while (num >= 16)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_itoa_hex(uintptr_t num, char *base)
{
	char	*hex;
	int		len;

	len = ft_hex_len(num);
	hex = (char *)ft_calloc(len + 1, sizeof(char));
	if (!hex)
		return (NULL);
	while (len--)
	{
		hex[len] = base[num % 16];
		num /= 16;
	}
	return (hex);
}

int	ft_puthex(unsigned int num, int fd, int uppercase)
{
	char	*hex;
	int		len;

	if (uppercase)
		hex = ft_itoa_hex((unsigned int) num, "0123456789ABCDEF");
	else
		hex = ft_itoa_hex((unsigned int) num, "0123456789abcdef");
	if (!hex)
		return (-1);
	len = ft_putstr(hex, fd);
	free(hex);
	return (len);
}
