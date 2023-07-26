/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:10:34 by arobu             #+#    #+#             */
/*   Updated: 2023/07/13 13:48:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBOID_H
# define CUBOID_H
# include "rect.h"
# include "shape.h"
# include "vec3.h"

typedef struct s_cuboid_data
{
	t_vec3			center;
	t_vec3			axis;
	double			width;
	double			height;
	double			depth;
	t_rect			**faces;
	t_vec3			u;
	t_vec3			v;
}					t_cuboid_data;

typedef struct s_cuboid
{
	t_shape			shape;
	t_cuboid_data	*data;
}					t_cuboid;

t_cuboid			*create_cuboid(t_cuboid_data data, t_material material);
t_shapes			cuboid_get_name_override(t_shape *self);
void				cuboid_destroy_override(t_shape *shape);
bool				cuboid_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit);
t_shape				*cuboid_to_shape(t_cuboid *cuboid);
t_cuboid			*cuboid_from_shape(t_shape *shape);

#endif