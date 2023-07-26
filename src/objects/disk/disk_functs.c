/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:34:17 by arobu             #+#    #+#             */
/*   Updated: 2023/07/05 15:34:18 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "shape.h"

t_shape	*disk_to_shape(t_disk *disk)
{
	return ((t_shape *)disk);
}

t_disk	*disk_from_shape(t_shape *shape)
{
	if (!shape)
		return ((t_disk *)NULL);
	return ((t_disk *)shape);
}

t_disk_data	*disk_get_data(t_disk *self)
{
	t_shape	*shape;

	shape = disk_to_shape(self);
	return ((t_disk_data *)shape_get_data(shape));
}

t_shapes	disk_get_name_override(t_shape *self)
{
	return ((t_shapes)DISK);
}

void	disk_destroy_override(t_shape *shape)
{
	t_disk	*disk;

	disk = disk_from_shape(shape);
	free(shape->shape_data);
	free(shape->shape_info);
	free(disk);
}
