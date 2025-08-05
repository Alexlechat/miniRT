/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:41:59 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c, int fd);
int		ft_putstr(char *str, int fd);
int		ft_putnbr(long n, int fd);
char	*ft_itoa_hex(uintptr_t num, char *base);
int		ft_putptr(void *ptr, int fd);
int		ft_puthex(unsigned int num, int fd, int uppercase);
int		ft_putunsigned(unsigned int num, int fd);

#endif