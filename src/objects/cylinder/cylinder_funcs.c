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

t_shapes	cylinder_get_name_override(t_shape *self)
{
	return ((t_shapes)CYLINDER);
}

void	cylinder_destroy_override(t_shape *self)
{
	t_cylinder *cylinder;

	cylinder = cyl_from_shape(self);
	free(self->shape_data);
	free(self->shape_info);
	free(cylinder);
}

t_shape 	*cyl_to_shape(t_cylinder *cyl)
{
	return ((t_shape *)cyl);
}

t_cylinder 	*cyl_from_shape(t_shape *shape)
{
	if (!shape)
		return ((t_cylinder *)NULL);
	return ((t_cylinder *)shape);
}