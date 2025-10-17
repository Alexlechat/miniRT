/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:57:14 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 11:36:47 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "../mlx_linux/mlx.h"
# include "elements.h"
# include "objects.h"

# define KEY_ESC 65307  // ESC
# define EVENT_CLOSE 17 // (cross X)
# define DEFAULT_HEIGHT 1000
# define DEFAULT_WIDTH 1600
# define ORIGIN_Z 0
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xe8eb34
# define ORANGE 0xff8000
# define EPSILON 0.001

typedef struct s_viewport
{
	double		norm_x;
	double		norm_y;
	double		height;
	double		width;
	double		ratio;
}				t_viewport;

typedef struct s_lighting
{
	double		ambient_r;
	double		ambient_g;
	double		ambient_b;
	double		diffuse_r;
	double		diffuse_g;
	double		diffuse_b;
}				t_lighting;

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

// -----------------------CALCULATE---------------------
void			apply_lighting(t_hit *hit, t_lighting lighting);
t_lighting		calculate_ambient(t_display *display, t_hit hit);
t_lighting		calculate_diffuse(t_display *display, t_hit hit,
					t_lighting lighting);
t_camera_basis	calculate_camera_basis(t_vector or);
t_viewport		calculate_viewport(t_display *display, int pixel_x,
					int pixel_y);

// -----------------------INTERSECTION---------------------
bool			check_cylinder_caps(t_cylinder *cylinder, t_ray *ray,
					t_hit *hit, double t);
bool			check_cap_distance(t_vector hit_point, t_vector cap_center,
					t_cylinder *cylinder);
bool			calculate_cap_hit(t_cylinder *cylinder, t_ray *ray, t_hit *hit,
					double cap_offset);
void			set_cap_normal(t_hit *hit, t_cylinder *cylinder, double offset);
bool			intersect_cap(t_cylinder *cylinder, t_ray *ray, t_hit *hit,
					double cap_offset);
t_vector		calculate_ray_perp(t_cylinder *cylinder, t_ray *ray);
t_vector		calculate_oc_perp(t_cylinder *cylinder, t_vector *oc);
void			fill_cylinder_hit(t_hit *hit, t_cylinder *cylinder,
					t_vector point, double t);
void			update_hit_if_closer(t_hit *hit, t_hit *cap_hit);
double			cylinder_intersection(t_display *display, t_cylinder *cylinder,
					t_ray *ray, t_hit *hit);
t_hit			find_closest_hit(t_display *display, t_ray ray);
t_hit			update_closest_hit(t_hit closest_hit, t_hit last_hit);
double			plane_intersection(t_display *display, t_plane *plane,
					t_ray *ray, t_hit *hit);
double			sphere_intersection(t_display *display, t_sphere *sphere,
					t_ray *ray, t_hit *hit);

void			init_window(t_display *display);
void			init_display(t_display *display);

int				close_window(t_display *display);
int				key_press(int key_code, t_display *display);
int				render_scene(t_display *display);
int				create_ray(t_display *display, int pixel_x, int pixel_y);
t_hit			find_closest_hit(t_display *display, t_ray ray);

bool			reflection(t_display *display, t_vector origin,
					t_hit *hit_object);
t_vector		calculate_light_ray(t_vector origin, t_light *light);
t_vector		sphere_normal(t_sphere *sphere, t_vector *coordinate);
t_vector		cylinder_normal(t_cylinder *cylinder, t_vector *coordinate);

#endif