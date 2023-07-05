/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:19:42 by arobu             #+#    #+#             */
/*   Updated: 2023/05/30 17:39:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_shape_info	*shape_get_info(t_shape	*self)
{
	return (self->shape_info);
}

t_material	*shape_get_material(t_shape *self)
{
	return (&self->material);
}

void	*shape_get_data(t_shape *self)
{
	return (self->shape_data);
}
