/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:37:32 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/29 09:47:47 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <stdlib.h>

void	init_display(t_display *display)
{
	display->sphere = NULL;
	display->plane = NULL;
	display->cylinder = NULL;
	display->height = DEFAULT_HEIGHT;
	display->width = DEFAULT_WIDTH;
}
