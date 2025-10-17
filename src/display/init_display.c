/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:37:32 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/17 12:53:02 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include <stdlib.h>

void	init_display(t_display *display)
{
	display->height = DEFAULT_HEIGHT;
	display->width = DEFAULT_WIDTH;
}
