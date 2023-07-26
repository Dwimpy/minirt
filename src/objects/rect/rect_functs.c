/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:40:41 by arobu             #+#    #+#             */
/*   Updated: 2023/07/26 21:06:44 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"

t_shapes	rect_get_name_override(t_shape *self)
{
	return ((t_shapes)RECT);
}

t_rect_data	*rect_get_data(t_rect *self)
{
	t_shape	*shape;

	shape = rect_to_shape(self);
	return ((t_rect_data *)shape_get_data(shape));
}

void	rect_destroy_override(t_shape *shape)
{
	t_rect	*rect;

	rect = rect_from_shape(shape);
	free(shape->shape_data);
	free(shape->shape_info);
	free(rect);
}

t_shape	*rect_to_shape(t_rect *rect)
{
	return ((t_shape *)rect);
}

t_rect	*rect_from_shape(t_shape *shape)
{
	if (!shape)
		return ((t_rect *)NULL);
	return ((t_rect *)shape);
}
