/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:42:27 by arobu             #+#    #+#             */
/*   Updated: 2023/05/22 17:50:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "ft_printf.h"

t_shape_info	*shape_type_create(t_shape_info	info)
{
	t_shape_info	*shape_info;

	shape_info = (t_shape_info *)malloc(sizeof(t_shape_info));
	shape_info->name = info.name;
	shape_info->hit = info.hit;
	shape_info->destroy = info.destroy;
	return (shape_info);
}

t_shape	*shape_create(t_shape_info *shape_info)
{
	size_t	size;
	t_shape	*shape;

	size = sizeof(t_shape);
	shape = (t_shape *)malloc(size);
	shape->shape_info = shape_info;
	return (shape);
}

t_shape_info	*shape_get_name(t_shape	*self)
{
	return (self->shape_info);
}

void	*shape_get_data(t_shape *self)
{
	return (self->shape_data);
}

void	shape_destroy(t_shape *self)
{
	if (self)
		self->shape_info->destroy(self);
}
