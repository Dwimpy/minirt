/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:57:59 by arobu             #+#    #+#             */
/*   Updated: 2023/07/02 18:30:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CYLINDER_H
# define CYLINDER_H

#include "vec3.h"
#include "shape.h"
#include "ray.h"

typedef struct s_cylinder_data{
	t_vec3		center;
	t_vec3		axis;
	double		radius;
	double		height;
}				t_cylinder_data;

typedef struct s_cylinder{
	t_shape			shape;
	t_cylinder_data	*data;
}				t_cylinder;

t_shapes	cylinder_get_name_override(t_shape *self);
t_cylinder	*create_cylinder(t_cylinder_data data, t_material material);
void		cylinder_destroy_override(t_shape *self);
bool		cylinder_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit);
t_shape		*cyl_to_shape(t_cylinder *cyl);
t_cylinder	*cyl_from_shape(t_shape *shape);
double		get_quadratic_term(t_cylinder *cyl, t_ray *ray);
double		get_linear_term(t_cylinder *cyl, t_ray *ray, t_vec3 oc);
double		get_constant_term(t_cylinder *cyl, t_vec3 oc);


#endif
