/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:26:20 by arobu             #+#    #+#             */
/*   Updated: 2023/07/11 13:26:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_H
#define RECT_H
#include "shape.h"
#include "vec3.h"

typedef struct s_rect_data {
	t_vec3	center;
	t_vec3	axis;
	double	width;
	double	height;
	t_vec3	corners[4];
	t_vec3	u;
	t_vec3	v;
} t_rect_data;

typedef struct s_rect {
	t_shape shape;
	t_rect_data *data;
} t_rect;

t_rect		*create_rect(t_rect_data data, t_material material);
t_shapes	rect_get_name_override(t_shape *self);
void		rect_destroy_override(t_shape *shape);
bool		rect_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit);
t_shape 	*rect_to_shape(t_rect *rect);
t_rect		*rect_from_shape(t_shape *shape);
void		compute_corners(t_rect_data *data);
bool		is_p_in_rectangle(t_rect *rect, t_vec3 point);
void		compute_uv_axes(t_rect_data *data);



#endif