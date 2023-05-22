/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:45:03 by arobu             #+#    #+#             */
/*   Updated: 2023/05/22 20:01:02 by arobu            ###   ########.fr       */
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

double	sphere_hit(t_shape *shape, t_ray *ray)
{
	t_sphere	*sphere;
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		disc;

	sphere = sphere_from_shape(shape);
	oc = vec_sub(ray->pos, sphere->data->center);
	a = vec_dot(ray->dir, ray->dir);
	half_b = vec_dot(oc, ray->dir);
	c = vec_magnitude_squared(oc) - sphere->data->radius * sphere->data->radius;
	disc = half_b * half_b - a * c;
	if (disc < 0)
		return (-1.0f);
	else
		return ((((-1) * half_b) - sqrt(disc)) / (a));
}
