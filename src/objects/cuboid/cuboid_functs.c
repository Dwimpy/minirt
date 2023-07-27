/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:41:03 by arobu             #+#    #+#             */
/*   Updated: 2023/07/13 13:46:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuboid.h"
#include "rect.h"
#include "shape.h"

t_shapes	cuboid_get_name_override(t_shape *self)
{
	return ((t_shapes)CUBOID);
}

t_cuboid_data	*cuboid_get_data(t_cuboid *self)
{
	t_shape	*shape;

	shape = cuboid_to_shape(self);
	return ((t_cuboid_data *)shape_get_data(shape));
}

void	cuboid_destroy_override(t_shape *shape)
{
	t_cuboid	*cuboid;
	t_rect		**faces;
	t_shape 	*shape_face;
	t_rect		*rect_face;
	int 		i;

	i = 0;
	cuboid = cuboid_from_shape(shape);
	faces = cuboid->data->faces;
	while (i < 6)
	{
		shape_face = rect_to_shape(faces[i]);
		rect_face = rect_from_shape(shape_face);
		free(shape_face->shape_info);
		free(shape_face->shape_data);
		free(faces[i]);
		i++;
	}
	free(cuboid->data->faces);
	free(shape->shape_data);
	free(shape->shape_info);
	free(cuboid);
}

t_shape	*cuboid_to_shape(t_cuboid *rect)
{
	return ((t_shape *)rect);
}

t_cuboid	*cuboid_from_shape(t_shape *shape)
{
	if (!shape)
		return ((t_cuboid *)NULL);
	return ((t_cuboid *)shape);
}