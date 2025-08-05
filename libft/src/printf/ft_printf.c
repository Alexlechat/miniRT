/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:39:27 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int), 1));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *), 1));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int), 1));
	if (format == 'p')
		return (ft_putptr(va_arg(args, void *), 1));
	if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 1, 0));
	if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1, 1));
	if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int), 1));
	if (format == '%')
		return (ft_putchar('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;
	int		tmp;

	printed_chars = 0;
	va_start(args, format);
	while (*format && printed_chars >= 0)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			tmp = ft_format(args, *format);
		}
		else
			tmp = ft_putchar(*format, 1);
		if (tmp == -1)
			printed_chars = -1;
		else
			printed_chars += tmp;
		format++;
	}
	va_end(args);
	return (printed_chars);
}
