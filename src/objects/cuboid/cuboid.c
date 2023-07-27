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
#include "rect.h"

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

void	create_cuboid_normals(t_vec3 *uvw, t_cuboid_data data)
{
	uvw[0] = data.axis;
	uvw[1] = data.u;
	uvw[2] = data.v;
	uvw[3] = vec_scale(-1, data.axis);
	uvw[4] = vec_scale(-1, data.u);
	uvw[5] = vec_scale(-1, data.v);
}

t_rect	*create_face(int idx, t_cuboid_data data, t_material material)
{
	t_rect_data	new_data;
	t_rect		*new_rect;
	t_vec3		uvw[6];
	double		size[3];

	get_face_height(idx, size, data);
	create_cuboid_normals(uvw, data);
	new_data.width = size[0];
	new_data.height = size[1];
	new_data.axis = uvw[idx % 6];
	new_data.u = uvw[(idx + 1) % 6];
	new_data.v = uvw[(idx + 2) % 6];
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