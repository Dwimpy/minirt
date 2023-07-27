/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:23:07 by arobu             #+#    #+#             */
/*   Updated: 2023/05/30 17:38:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "color.h"
#include "texture.h"
#include "vec3.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

t_sphere *create_sphere(double radius, t_vec3 center, t_material material, t_texture texture) {
	t_shape_info *sphere_info;
	t_sphere *sphere;
	t_sphere_data *sph_data;

	sphere_info = shape_type_create((t_shape_info) {
		sphere_get_name_override, sphere_hit, sphere_destroy_override});
	sphere = (t_sphere *) shape_create(sphere_info);
	sph_data = (t_sphere_data *) malloc(sizeof(t_sphere_data));
	sph_data->center = center;
	sph_data->radius = radius;
	sphere->data = sph_data;
	sphere->shape.shape_data = (t_sphere_data *) sph_data;
	sphere->shape.material = material;
	sphere->shape.texture = texture;
	return (sphere);
}

bool	sphere_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit)
{
	t_sphere	*sphere;
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		disc;
	double		sqrt_disc;
	double		root;

	sphere = sphere_from_shape(shape);
	oc = vec_sub(ray->pos, sphere->data->center);
	a = vec_dot(ray->dir, ray->dir);
	half_b = vec_dot(oc, ray->dir);
	c = vec_magnitude_squared(oc) - sphere->data->radius * sphere->data->radius;
	disc = half_b * half_b - a * c;
	if (disc < 0.0)
		return (false);
	sqrt_disc = sqrt(disc);
	root = (-half_b - sqrt_disc) / a;
	if (root < hit->min_t || hit->max_t < root)
	{
		root = (-half_b + sqrt_disc) / a;
		if (root < hit->min_t || hit->max_t < root)
			return (false);
	}
	if (root > hit->t)
		return (false);
	hit->t = root;
	hit->material = &sphere->shape.material;
	hit->isec_point = value_at(ray, hit->t);
	hit->surf_normal = vec_sub(hit->isec_point, sphere->data->center);
	hit->surf_normal = vec_scale(1 / sphere->data->radius, hit->surf_normal);
	hit->max_t = hit->t;
	hit->texture = &sphere->shape.texture;
	set_front_face(ray, hit);
	return (true);
}
