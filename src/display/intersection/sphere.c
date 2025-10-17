/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:56:17 by allefran          #+#    #+#             */
/*   Updated: 2025/10/17 11:26:12 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "vectors.h"

static void		solve_sphere_quadratic(t_quadratic *quad, t_sphere *sphere,
					t_ray *ray);
static double	check_sphere_hit(t_ray *ray, t_sphere *sphere, t_hit *hit,
					double x);

double	sphere_intersection(t_display *display, t_sphere *sphere, t_ray *ray,
		t_hit *hit)
{
	t_quadratic	quad;
	double		result;

	(void)display;
	solve_sphere_quadratic(&quad, sphere, ray);
	if (quad.delta < 0)
		return (0);
	result = check_sphere_hit(ray, sphere, hit, quad.solution_1);
	if (result > 0)
		return (result);
	return (check_sphere_hit(ray, sphere, hit, quad.solution_2));
}

static void	solve_sphere_quadratic(t_quadratic *quad, t_sphere *sphere,
		t_ray *ray)
{
	t_vector	co;

	co = substract(ray->origin, sphere->position);
	quad->a = dot(ray->direction, ray->direction);
	quad->b = 2 * dot(co, ray->direction);
	quad->c = dot(co, co) - (sphere->radius * sphere->radius);
	solve_quadratic(quad);
}

static double	check_sphere_hit(t_ray *ray, t_sphere *sphere, t_hit *hit,
		double x)
{
	if (x >= EPSILON)
	{
		hit->hit = true;
		hit->coordinate = add(ray->origin, multiply(ray->direction, x));
		hit->distance = x;
		hit->color = sphere->color;
		hit->normal = sphere_normal(sphere, &hit->coordinate);
		return (x);
	}
	return (0);
}
