/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:45:03 by arobu             #+#    #+#             */
/*   Updated: 2023/07/02 21:27:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include <stdlib.h>

t_shapes sphere_get_name_override(t_shape *self) { return ((t_shapes) SPHERE); }

void sphere_destroy_override(t_shape *shape) {
	t_sphere *the_sphere;

	the_sphere = sphere_from_shape(shape);
	free(shape->shape_data);
	free(shape->shape_info);
	free(the_sphere);
}

t_shape *sphere_to_shape(t_sphere *sphere) { return ((t_shape *) sphere); }

t_sphere *sphere_from_shape(t_shape *shape) {
	if (!shape)
		return ((t_sphere *) NULL);
	return ((t_sphere *) shape);
}

t_sphere_data *sphere_get_data(t_sphere *self) {
	t_shape *shape;

	shape = (t_shape *) self;
	return ((t_sphere_data *) shape_get_data(shape));
}
