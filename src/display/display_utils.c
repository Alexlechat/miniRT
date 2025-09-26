/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:04:10 by allefran          #+#    #+#             */
/*   Updated: 2025/09/25 15:54:46 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	convert_color(t_color color)
{
	int	hex;

	hex = 0;
	hex = color.r << 16;
	hex = hex | color.g << 8;
	hex = hex | color.b;
	return (hex);
}
