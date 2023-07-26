/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:44:47 by arobu             #+#    #+#             */
/*   Updated: 2023/07/05 17:44:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "shape.h"

t_shape	*plane_to_shape(t_plane *plane)
{
	return ((t_shape *)plane);
}

t_plane	*plane_from_shape(t_shape *shape)
{
	if (!shape)
		return ((t_plane *)NULL);
	return ((t_plane *)shape);
}

t_plane_data	*plane_get_data(t_plane *self)
{
	t_shape	*shape;

	shape = plane_to_shape(self);
	return ((t_plane_data *)shape_get_data(shape));
}

t_shapes	plane_get_name_override(t_shape *self)
{
	return ((t_shapes)PLANE);
}

void	plane_destroy_override(t_shape *shape)
{
	t_plane	*plane;

	plane = plane_from_shape(shape);
	free(shape->shape_data);
	free(shape->shape_info);
	free(plane);
}
