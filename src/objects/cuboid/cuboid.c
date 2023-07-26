/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:10:34 by arobu             #+#    #+#             */
/*   Updated: 2023/07/14 18:24:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuboid.h"

t_cuboid	*create_cuboid(t_cuboid_data data, t_material material)
{
	t_cuboid		*cuboid;
	t_cuboid_data	*cuboid_data;
	t_shape_info	*cuboid_info;
	t_vec3			coords[6];
	int				i;

	i = -1;
	cuboid_info = shape_type_create(
		(t_shape_info){
			cuboid_get_name_override,
			cuboid_hit,
			cuboid_destroy_override});
	cuboid = (t_cuboid *)shape_create(cuboid_info);
	cuboid_data = (t_cuboid_data *)malloc(sizeof(t_cuboid_data));
	data.faces = (t_rect **)malloc(sizeof(t_rect *) * 6);
	data.axis = vec_normalize(data.axis);
	vec3_compute_uv_axes(data.axis, &data.u, &data.v);
	while (++i < 6)
		data.faces[i] = create_face(i, data, material);
	*cuboid_data = data;
	cuboid->data = cuboid_data;
	cuboid->shape.shape_data = cuboid_data;
	cuboid->shape.material = material;
	return (cuboid);
}

void	get_face_height(int idx, double *size, t_cuboid_data data)
{
	if (idx == 0 || idx == 3)
	{
		size[0] = data.width;
		size[1] = data.height;
		size[2] = data.depth;
	}
	else if (idx == 1 || idx == 4)
	{
		size[0] = data.height;
		size[1] = data.depth;
		size[2] = data.width;
	}
	else if (idx == 2 || idx == 5)
	{
		size[0] = data.depth;
		size[1] = data.width;
		size[2] = data.height;
	}
}

t_rect	*create_face(int idx, t_cuboid_data data, t_material material)
{
	t_rect_data	new_data;
	t_rect		*new_rect;
	double		size[3];

	get_face_height(idx, size, data);
	new_data.width = size[0];
	new_data.height = size[1];
	if (idx == 0)
	{
		new_data.axis = data.axis;
		new_data.u = data.u;
		new_data.v = data.v;
	}
	else if (idx == 3)
	{
		new_data.axis = vec_scale(-1, data.axis);
		new_data.u = vec_scale(-1, data.u);
		new_data.v = vec_scale(-1, data.v);
	}
	if (idx == 1)
	{
		new_data.axis = data.u;
		new_data.u = data.v;
		new_data.v = vec_scale(-1, data.axis);
	}
	else if (idx == 4)
	{
		new_data.axis = vec_scale(-1, data.u);
		new_data.u = vec_scale(-1, data.v);
		new_data.v = data.axis;
	}
	if (idx == 2)
	{
		new_data.axis = data.v;
		new_data.u = vec_scale(-1, data.axis);
		new_data.v = vec_scale(-1, data.u);
	}
	else if (idx == 5)
	{
		new_data.axis = vec_scale(-1, data.v);
		new_data.u = data.axis;
		new_data.v = data.u;
	}
	new_data.center = vec_add(data.center, vec_scale(size[2] * 0.5,
				new_data.axis));
	new_rect = create_cuboid_face(new_data, material);
	return (new_rect);
}

bool	cuboid_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit)
{
	t_cuboid *cuboid;
	t_shape *face;
	bool hit_anything;
	int i;

	cuboid = cuboid_from_shape(shape);
	hit_anything = false;
	i = 0;
	while (i < 6)
	{
		face = rect_to_shape(cuboid->data->faces[i]);
		if (cuboid->data->faces[i]->shape.shape_info->hit(face, ray, hit))
			hit_anything = true;
		i++;
	}
	if (hit_anything)
		return (true);
	return (false);
}