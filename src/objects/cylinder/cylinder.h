/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:57:59 by arobu             #+#    #+#             */
/*   Updated: 2023/07/10 23:35:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CYLINDER_H
# define CYLINDER_H

# include "disk.h"
# include "vec3.h"
# include "shape.h"
# include "ray.h"

typedef struct s_cylinder_data
{
	t_vec3		center;
	t_vec3		axis;
	double		radius;
	double		height;
	t_disk		*upper;
	t_disk		*lower;
}				t_cylinder_data;

typedef struct s_cylinder
{
	t_shape			shape;
	t_cylinder_data	*data;
}				t_cylinder;

t_shapes	cylinder_get_name_override(t_shape *self);
t_cylinder	*create_cylinder(t_cylinder_data data, t_material material);
void		cylinder_destroy_override(t_shape *self);
bool		cylinder_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit);
t_shape		*cyl_to_shape(t_cylinder *cyl);
t_cylinder	*cyl_from_shape(t_shape *shape);
double		get_quadratic_term(t_vec3 r_dir, t_vec3 cyl_axis);
double		get_linear_term(t_vec3 oc, t_vec3 r_dir, t_vec3 cyl_axis);
double		get_constant_term(t_vec3 oc, t_vec3 r_dir, t_cylinder *cyl);
bool		get_intersection_root(double a, double b, double c, double t[2]);
t_vec3		cyl_normal_at(t_cylinder *cyl, t_ray *ray, \
							t_vec3 oc, t_hit_rec *hit);

#endif
