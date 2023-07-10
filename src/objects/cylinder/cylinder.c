/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:58:03 by arobu             #+#    #+#             */
/*   Updated: 2023/07/10 23:59:02 by arobu            ###   ########.fr       */
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
	data.axis = vec_normalize(data.axis);
	data.lower = create_disk((t_disk_data){
			data.center,
			vec_scale(-1, data.axis),
			data.radius}, material);
	data.upper = create_disk((t_disk_data){
			vec_add(data.center, vec_scale(data.height, data.axis)),
			data.axis,
			data.radius}, material);
	data.center = vec_add(data.center, vec_scale(data.height / 2.0, data.axis));
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

bool	cyl_height(t_cylinder *cyl, t_ray *ray, t_hit_rec *hit, double *t)
{
	t_vec3	point;
	t_vec3	oc;
	double	dist_to_p;

	point = value_at(ray, *t);
	oc = vec_sub(cyl->data->center, point);
	dist_to_p = vec_dot(oc, cyl->data->axis);
	if (fabs(dist_to_p) > cyl->data->height / 2.0)
		return (false);
	hit->t = *t;
	hit->max_t = *t;
	hit->isec_point = point;
	hit->surf_normal = cyl_normal_at(cyl, ray, oc, hit);
	set_front_face(ray, hit);
	return (true);
}

bool	cyl_caps(t_cylinder *cyl, t_ray *ray, t_hit_rec *hit)
{
	bool	hit_anything;
	t_disk	*upper;
	t_disk	*lower;

	upper = cyl->data->upper;
	lower = cyl->data->lower;
	hit_anything = false;
	if (upper->shape.shape_info->hit(&upper->shape, ray, hit))
		hit_anything = true;
	if ((lower->shape.shape_info->hit(&lower->shape, ray, hit)))
		hit_anything = true;
	if (hit_anything)
		return (true);
	return (false);
}

bool	cylinder_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit)
{
	t_cylinder	*cyl;
	t_vec3		oc;
	double		a;
	double		b;
	double		c;
	double		t[2];

	cyl = cyl_from_shape(shape);
	oc = vec_sub(ray->pos, cyl->data->center);
	cyl->data->axis = vec_normalize(cyl->data->axis);
	a = get_quadratic_term(ray->dir, cyl->data->axis);
	b = get_linear_term(oc, ray->dir, cyl->data->axis);
	c = get_constant_term(oc, ray->dir, cyl);

	if (!get_intersection_root(a, b, c, t))
		return (false);
	hit->material = &cyl->shape.material;
	if (t[0] > 0.0 && t[0] < hit->max_t && cyl_height(cyl, ray, hit, &t[0]))
		return (true);
	if (cyl_caps(cyl, ray, hit))
		return (true);
	if (t[1] > 0.0 && t[1] < hit->max_t && cyl_height(cyl, ray, hit, &t[1]))
		return (true);
	return (false);
}
