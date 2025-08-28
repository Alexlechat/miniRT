/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:57:14 by allefran          #+#    #+#             */
/*   Updated: 2025/08/28 11:07:33 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "../mlx_linux/mlx.h"

# define KEY_ESC 65307   // ESC
# define EVENT_CLOSE 17  // (cross X)

typedef struct s_display
{
	void	*mlx;
	void	*window;
	int		height;
	int		width;
}			t_display;

void	init_window(t_display *display);
int		close_window(t_display *display);
int		key_press(int key_code, t_display *display);

#endif