/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:45:03 by arobu             #+#    #+#             */
/*   Updated: 2023/05/26 13:56:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include <stdlib.h>

t_shapes	sphere_get_name_override(t_shape *self)
{
	return ((t_shapes)SPHERE);
}

void	sphere_destroy_override(t_shape *shape)
{
	t_sphere	*the_sphere;

	the_sphere = sphere_from_shape(shape);
	free(shape->shape_data);
	free(shape->shape_info);
	free(the_sphere);
}

bool	sphere_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit)
{
	t_sphere	*sphere;
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		disc;
	double		sqrt_disc;
	double		root;

	*hit = new_hit_rec();
	sphere = sphere_from_shape(shape);
	oc = vec_sub(ray->pos, sphere->data->center);
	a = vec_dot(ray->dir, ray->dir);
	half_b = vec_dot(oc, ray->dir);
	c = vec_magnitude_squared(oc) - sphere->data->radius * sphere->data->radius;
	disc = half_b * half_b - a * c;
	if (disc < 0.0)
		return (false);
	sqrt_disc = sqrt(disc);
	root = (-half_b - sqrt_disc) / a;
	if (root < hit->min_t || hit->max_t < root)
	{
		root = (-half_b + sqrt_disc) / a;
		if (root < hit->min_t || hit->max_t < root)
			return (false);
	}
	hit->t = root;
	hit->isec_point = value_at(ray, hit->t);
	hit->surf_normal = vec_sub(hit->isec_point, sphere->data->center);
	hit->surf_normal = vec_scale(1 / sphere->data->radius, hit->surf_normal);
	set_front_face(ray, hit);
	return (true);
}
