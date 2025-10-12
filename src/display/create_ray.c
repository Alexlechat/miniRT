/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:08:36 by allefran          #+#    #+#             */
/*   Updated: 2025/10/12 14:22:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "display.h"
#include "vectors.h"
#include "camera_basis.h"

void	apply_lighting(t_display *display, t_hit *hit);

int	create_ray(t_display *display, int pixel_x, int pixel_y)
{
	double			norm_x;
	double			norm_y;
	t_ray			ray;
	t_hit			hit;
	t_camera_basis	basis;

	norm_x = ((2 * pixel_x / (double)display->width) - 1);
	norm_y = 1 - (2 * pixel_y / (double)display->height);
	basis = calculate_camera_basis(display->camera.orientation);
	hit.hit = false;
	hit.color.color = display->ambient.color.color;
	ray.origin = display->camera.position;
	ray.direction = calculate_ray_direction(basis, norm_x, norm_y, display);
	hit = find_closest_hit(display, ray);
	if (hit.hit == true)
		apply_lighting(display, &hit);
	mlx_pixel_put(display->mlx, display->window, pixel_x, pixel_y,
		hit.color.color);
	return (0);
}

void	check_spheres(t_display *display, t_ray *ray, t_hit *closest);
void	check_planes(t_display *display, t_ray *ray, t_hit *closest);
void	check_cylinders(t_display *display, t_ray *ray, t_hit *closest);

t_hit	find_closest_hit(t_display *display, t_ray ray)
{
	t_hit	closest_hit;

	ft_memset(&closest_hit, 0, sizeof(t_hit));
	closest_hit.hit = false;
	check_spheres(display, &ray, &closest_hit);
	check_planes(display, &ray, &closest_hit);
	check_cylinders(display, &ray, &closest_hit);
	if (closest_hit.hit == false)
		closest_hit.color.color = 0;
	return (closest_hit);
}
