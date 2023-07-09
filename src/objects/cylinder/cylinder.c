/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:58:03 by arobu             #+#    #+#             */
/*   Updated: 2023/07/03 15:15:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "hit_record.h"
#include "libft.h"
#include "ray.h"
#include "shape.h"
#include "tester.h"
#include "transform.h"
#include "vec3.h"

t_cylinder	*create_cylinder(t_cylinder_data data, t_material material)
{
	t_shape_info	*cyl_info;
	t_cylinder		*cylinder;
	t_cylinder_data	*cyl_data;

	cyl_info = shape_type_create((t_shape_info){
			cylinder_get_name_override,
			cylinder_hit,
			cylinder_destroy_override
		});
	cylinder = (t_cylinder *) shape_create(cyl_info);
	cyl_data = (t_cylinder_data *) ft_calloc(1, sizeof(t_cylinder_data));
	*cyl_data = data;
	cylinder->data = cyl_data;
	cylinder->shape.shape_data = (t_cylinder_data *) cyl_data;
	cylinder->shape.material = material;
	return (cylinder);
}

t_vec3	cyl_normal_at(t_cylinder *cyl, t_ray *ray, t_vec3 oc, t_hit_rec *hit)
{
	double	m;
	double	a;
	double	b;

	a = vec_dot(ray->dir, cyl->data->axis);
	b = vec_dot(oc, cyl->data->axis);
	m = a * hit->t + b;
	return (vec_normalize(\
		vec_sub(\
		vec_sub(hit->isec_point, cyl->data->center), \
		vec_scale(m, cyl->data->axis))));
}

bool	cylinder_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit)
{
	t_cylinder	*cyl;
	t_vec3		oc;
	double		a;
	double		b;
	double		c;

	cyl = cyl_from_shape(shape);
	oc = vec_sub(ray->pos, cyl->data->center);
	cyl->data->axis = vec_normalize(cyl->data->axis);
	a = get_quadratic_term(ray->dir, cyl->data->axis);
	b = get_linear_term(oc, ray->dir, cyl->data->axis);
	c = get_constant_term(oc, ray->dir, cyl);

	if (!get_intersection_root(a, b, c, hit))
		return (false);
	hit->material = &cyl->shape.material;
	hit->isec_point = value_at(ray, hit->t);
	hit->surf_normal = cyl_normal_at(cyl, ray, oc, hit);
	hit->max_t = fmin(hit->max_t, hit->t);
	set_front_face(ray, hit);
	return (true);
}