/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:42:27 by arobu             #+#    #+#             */
/*   Updated: 2023/05/30 18:02:01 by arobu            ###   ########.fr       */
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

	size = sizeof(t_shape) + sizeof(t_material);
	shape = (t_shape *)malloc(size + 1);
	shape->shape_info = shape_info;
	return (shape);
}
void	shape_destroy(t_shape *self)
{
	if (self)
		self->shape_info->destroy(self);
}
