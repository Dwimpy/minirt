/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:41:09 by arobu             #+#    #+#             */
/*   Updated: 2023/07/05 17:41:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
#define PLANE_H
#include "shape.h"
#include "vec3.h"

typedef struct s_plane_data {
	t_vec3 origin;
	t_vec3 axis;
} t_plane_data;

typedef struct s_plane {
	t_shape shape;
	t_plane_data *data;
} t_plane;

t_shapes plane_get_name_override(t_shape *self);
void plane_destroy_override(t_shape *shape);
bool plane_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit);
t_plane *create_plane(t_plane_data data, t_material material);
t_shape *plane_to_shape(t_plane *plane);
t_plane *plane_from_shape(t_shape *shape);

#endif