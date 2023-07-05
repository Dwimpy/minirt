/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:21:00 by arobu             #+#    #+#             */
/*   Updated: 2023/07/05 15:21:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "hit_record.h"
#include "ray.h"
#include "shape.h"
#include "vec3.h"
#include <float.h>

t_disk *create_disk(t_disk_data data, t_material material) {
	t_disk *disk;
	t_shape_info *disk_info;
	t_disk_data *disk_data;

	disk_info = shape_type_create((t_shape_info) {
			disk_get_name_override,
			disk_hit,
			disk_destroy_override
	});
	disk = (t_disk *) shape_create(disk_info);
	disk_data = (t_disk_data *) malloc(sizeof(t_disk_data));
	*disk_data = data;
	disk->data = disk_data;
	disk->shape.shape_data = (t_disk_data *) disk_data;
	disk->shape.material = material;
	return (disk);
}

bool disk_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit) {
	t_disk *disk;
	t_vec3 pc;
	double aligned;
	double root;
	t_hit_rec new_hit;

	disk = disk_from_shape(shape);
	aligned = vec_dot(disk->data->axis, ray->dir);
	if (fabs(aligned) < 1e-6)
		return false;

	pc = vec_sub(disk->data->origin, ray->pos);
	root = vec_dot(pc, disk->data->axis) / aligned;
	if (root <= hit->min_t || root > hit->max_t)
		return false;

	hit->isec_point = value_at(ray, root);
	t_vec3 pc_disk = vec_sub(hit->isec_point, disk->data->origin);
	double distance_squared = vec_magnitude_squared(pc_disk);

	if (distance_squared > disk->data->radius * disk->data->radius)
		return false;

	hit->surf_normal = disk->data->axis;
	hit->t = root;
	hit->max_t = fmin(hit->max_t, hit->t);
	hit->material = &shape->material;
	set_front_face(ray, hit);
	return true;
}