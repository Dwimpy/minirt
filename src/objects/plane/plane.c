/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:41:06 by arobu             #+#    #+#             */
/*   Updated: 2023/07/05 17:41:07 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "hit_record.h"
#include "shape.h"
#include "vec3.h"
#include <float.h>

t_plane *create_plane(t_plane_data data, t_material material) {
	t_plane *plane;
	t_shape_info *plane_info;
	t_plane_data *plane_data;

	plane_info = shape_type_create((t_shape_info) {
			plane_get_name_override,
			plane_hit,
			plane_destroy_override
	});
	plane = (t_plane *) shape_create(plane_info);
	plane_data = (t_plane_data *) malloc(sizeof(t_plane_data));
	*plane_data = data;
	plane->data = plane_data;
	plane->shape.shape_data = plane_data;
	plane->shape.material = material;
	return (plane);
}

bool plane_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit) {
	t_plane *plane;
	t_vec3 pc;
	t_vec3 pc_plane;
	double aligned;
	double root;

	plane = plane_from_shape(shape);
	aligned = vec_dot(plane->data->axis, ray->dir);
	if (fabs(aligned) < M_EPSILON)
		return (false);
	pc = vec_sub(plane->data->origin, ray->pos);
	root = vec_dot(pc, plane->data->axis) / aligned;
	if (root <= hit->min_t || root > hit->max_t)
		return (false);
	hit->t = root;
	hit->isec_point = value_at(ray, root);
	hit->surf_normal = plane->data->axis;
	hit->max_t = hit->t;
	hit->material = &shape->material;
	set_front_face(ray, hit);
	return (true);
}
