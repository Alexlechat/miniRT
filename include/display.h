/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:57:14 by allefran          #+#    #+#             */
/*   Updated: 2025/08/29 09:52:11 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "../mlx_linux/mlx.h"
# include "elements.h"
# include "objects.h"

# define KEY_ESC 65307   // ESC
# define EVENT_CLOSE 17  // (cross X)
# define DEFAULT_HEIGHT 600
# define DEFAULT_WIDTH 1000

typedef struct s_display
{
	void		*mlx;
	void		*window;
	int			height;
	int			width;
	int			nb_spheres;
	int			nb_planes;
	int			nb_cylinders;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}			t_display;

void	init_window(t_display *display);
int		close_window(t_display *display);
int		key_press(int key_code, t_display *display);
void	init_display(t_display *display);

#endif