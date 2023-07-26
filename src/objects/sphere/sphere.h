/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:08:41 by arobu             #+#    #+#             */
/*   Updated: 2023/05/30 17:38:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "hit_record.h"
# include "ray.h"
# include "shape.h"
# include "vec3.h"
# include <stdbool.h>

typedef struct s_sphere	t_sphere;

typedef struct s_sphere_data
{
	t_vec3				center;
	double				radius;
}						t_sphere_data;

typedef struct s_sphere
{
	t_shape				shape;
	t_sphere_data		*data;
}						t_sphere;

t_shapes				sphere_get_name_override(t_shape *self);
t_sphere				*create_sphere(double radius, t_vec3 center,
							t_material material);
void					sphere_destroy_override(t_shape *shape);
bool					sphere_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit);
t_shape					*sphere_to_shape(t_sphere *sphere);
t_sphere				*sphere_from_shape(t_shape *shape);

#endif
