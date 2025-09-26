/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:57:14 by allefran          #+#    #+#             */
/*   Updated: 2025/09/26 08:43:23 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "../mlx_linux/mlx.h"
# include "elements.h"
# include "objects.h"

# define KEY_ESC 65307  // ESC
# define EVENT_CLOSE 17 // (cross X)
# define DEFAULT_HEIGHT 600
# define DEFAULT_WIDTH 1000
# define ORIGIN_X (DEFAULT_WIDTH / 2)
# define ORIGIN_Y (DEFAULT_HEIGHT / 2)
# define ORIGIN_Z 0
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xe8eb34
# define ORANGE 0xff8000

typedef struct s_display
{
	void		*mlx;
	void		*window;
	int			height;
	int			width;
	int			nb_planes;
	int			nb_spheres;
	int			nb_cylinders;
	double		focal_length;
	t_vector	vector_offset;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}				t_display;

void			init_window(t_display *display);
void			init_display(t_display *display);

int				close_window(t_display *display);
int				key_press(int key_code, t_display *display);
int				render_scene(t_display *display);
int				draw_line(t_display *display, t_vector vector, int length,
					int color);
int				draw_position(t_display *display, int x, int y, int color);
int				create_ray(t_display *display, int pixel_x, int pixel_y);
double 			sphere_intersection(t_display *display, t_sphere *sphere, t_ray *ray, t_hit *hit);

#endif