/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:10:58 by arobu             #+#    #+#             */
/*   Updated: 2023/07/02 18:10:59 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "disk.h"
#include "shape.h"

t_shapes cylinder_get_name_override(t_shape *self) {
	return ((t_shapes) CYLINDER);
}

void cylinder_destroy_override(t_shape *self) {
	t_cylinder *cylinder;
	t_shape *upper;
	t_shape *lower;
	t_disk *u_disk;
	t_disk *l_disk;

	cylinder = cyl_from_shape(self);
	upper = disk_to_shape(cylinder->data->upper);
	lower = disk_to_shape(cylinder->data->lower);
	u_disk = disk_from_shape(upper);
	l_disk = disk_from_shape(lower);
	free(upper->shape_info);
	free(upper->shape_data);
	free(lower->shape_info);
	free(lower->shape_data);
	free(u_disk);
	free(l_disk);
	free(self->shape_data);
	free(self->shape_info);
	free(cylinder);
}

t_shape *cyl_to_shape(t_cylinder *cyl) { return ((t_shape *) cyl); }

t_cylinder *cyl_from_shape(t_shape *shape) {
	if (!shape)
		return ((t_cylinder *) (NULL));
	return ((t_cylinder *) shape);
}