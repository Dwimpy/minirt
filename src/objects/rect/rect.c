/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:26:18 by arobu             #+#    #+#             */
/*   Updated: 2023/07/13 16:52:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "hit_record.h"
#include "rect.h"
#include "shape.h"
#include "tester.h"
#include "vec3.h"
#include <math.h>

t_rect	*create_rect(t_rect_data data, t_material material)
{
	t_rect			*rect;
	t_rect_data		*rect_data;
	t_shape_info	*rect_info;

	rect_info = shape_type_create(
		(t_shape_info){rect_get_name_override, rect_hit,
			rect_destroy_override});
	rect = (t_rect *)shape_create(rect_info);
	rect_data = (t_rect_data *)malloc(sizeof(t_rect_data));
	data.axis = vec_normalize(data.axis);
	vec3_compute_uv_axes(data.axis, &data.u, &data.v);
	*rect_data = data;
	rect->data = rect_data;
	rect->shape.shape_data = rect_data;
	rect->shape.material = material;
	return (rect);
}

t_rect	*create_cuboid_face(t_rect_data data, t_material material)
{
	t_rect			*rect;
	t_rect_data		*rect_data;
	t_shape_info	*rect_info;

	rect_info = shape_type_create(
		(t_shape_info){rect_get_name_override, rect_hit,
			rect_destroy_override});
	rect = (t_rect *)shape_create(rect_info);
	rect_data = (t_rect_data *)malloc(sizeof(t_rect_data));
	*rect_data = data;
	rect->data = rect_data;
	rect->shape.shape_data = rect_data;
	rect->shape.material = material;
	return (rect);
}

bool	is_p_in_rectangle(t_rect *rect, t_vec3 point)
{
	t_vec3	pc;
	double	u_dist;
	double	v_dist;

	pc = vec_sub(point, rect->data->center);
	u_dist = vec_dot(rect->data->u, pc);
	v_dist = vec_dot(rect->data->v, pc);
	if (fabs(u_dist) > rect->data->width * 0.5 ||
		fabs(v_dist) > rect->data->height * 0.5)
		return (false);
	return (true);
}

bool	rect_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit)
{
	t_rect *rect;
	t_vec3 pc;
	t_vec3 point;
	double root;
	double aligned;

	rect = rect_from_shape(shape);
	aligned = vec_dot(rect->data->axis, ray->dir);
	if (fabs(aligned) < M_EPSILON)
		return (false);
	pc = vec_sub(rect->data->center, ray->pos);
	root = vec_dot(pc, rect->data->axis) / aligned;
	if (root < hit->min_t || root > hit->max_t)
		return (false);
	point = value_at(ray, root);
	if (!is_p_in_rectangle(rect, point))
		return (false);
	hit->isec_point = point;
	hit->t = root;
	hit->surf_normal = rect->data->axis;
	hit->max_t = hit->t;
	hit->material = &shape->material;
	set_front_face(ray, hit);
	return (true);
}