/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:21:03 by arobu             #+#    #+#             */
/*   Updated: 2023/07/05 15:21:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_H
#define DISK_H
#include "shape.h"
#include "vec3.h"

typedef struct s_disk_data {
	t_vec3 origin;
	t_vec3 axis;
	double radius;
} t_disk_data;

typedef struct s_disk {
	t_shape shape;
	t_disk_data *data;
} t_disk;

t_shapes disk_get_name_override(t_shape *self);
t_disk *create_disk(t_disk_data data, t_material material);
void disk_destroy_override(t_shape *shape);
bool disk_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit);
t_shape *disk_to_shape(t_disk *disk);
t_disk *disk_from_shape(t_shape *shape);

#endif