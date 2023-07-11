/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:06 by arobu             #+#    #+#             */
/*   Updated: 2023/05/30 19:11:58 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
#define SHAPE_H
#include "material.h"
#include <stdbool.h>

typedef struct s_shape t_shape;
typedef enum e_shapes t_shapes;
typedef bool (*t_shape_hit)(t_shape *shape, t_ray *ray, t_hit_rec *hit);
typedef void (*t_destroy)(t_shape *shape);
typedef t_shapes (*t_shape_name)(t_shape *self);

typedef enum e_shapes { SPHERE, DISK, PLANE, RECT, CYLINDER } t_shapes;

typedef struct s_shape_info {
	t_shape_name name;
	t_shape_hit hit;
	t_destroy destroy;
} t_shape_info;

typedef struct s_shape {
	t_shape_info *shape_info;
	t_material material;
	void *shape_data;
} t_shape;

t_shape *shape_create(t_shape_info *shape_type);
t_shape_info *shape_type_create(t_shape_info info);
t_shape_info *shape_get_info(t_shape *self);
void *shape_get_data(t_shape *self);
void shape_destroy(t_shape *self);
#endif
