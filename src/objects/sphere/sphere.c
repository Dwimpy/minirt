/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:23:07 by arobu             #+#    #+#             */
/*   Updated: 2023/05/23 12:15:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	
#include "sphere.h"
#include <math.h>
#include <stdlib.h>

t_sphere	*create_sphere(double radius, t_vec3 center)
{
	t_shape_info	*sphere_info;
	t_sphere		*sphere;
	t_sphere_data	*sph_data;

	sphere_info = shape_type_create((t_shape_info){
			sphere_get_name_override,
			sphere_hit,
			sphere_destroy_override
		});
	sphere = (t_sphere *)shape_create(sphere_info);
	sph_data = (t_sphere_data *)malloc(sizeof(t_sphere_data));
	sph_data->center = center;
	sph_data->radius = radius;
	sphere->data = sph_data;
	sphere->shape.shape_data = (t_sphere_data *)sph_data;
	return (sphere);
}

t_shape	*sphere_to_shape(t_sphere *sphere)
{
	return ((t_shape *)sphere);
}

t_sphere	*sphere_from_shape(t_shape *shape)
{
	if (!shape)
		return ((t_sphere *) NULL);
	return ((t_sphere *)shape);
}

t_sphere_data	*sphere_get_data(t_sphere *self)
{
	t_shape	*shape;

	shape = (t_shape *)self;
	return ((t_sphere_data *) shape_get_data(shape));
}

