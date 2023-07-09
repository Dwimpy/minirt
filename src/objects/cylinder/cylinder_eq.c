/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_eq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:57:58 by arobu             #+#    #+#             */
/*   Updated: 2023/07/09 17:57:59 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

double	get_quadratic_term(t_vec3 r_dir, t_vec3 cyl_axis)
{
	return (vec_dot(r_dir, r_dir) - \
			vec_dot(r_dir, cyl_axis) * \
			vec_dot(r_dir, cyl_axis));
}

double	get_linear_term(t_vec3 oc, t_vec3 r_dir, t_vec3 cyl_axis)
{
	return (2 * (vec_dot(r_dir, oc) - \
			vec_dot(r_dir, cyl_axis) * \
			vec_dot(oc, cyl_axis)));
}

double	get_constant_term(t_vec3 oc, t_vec3 r_dir, t_cylinder *cyl)
{
	return (vec_dot(oc, oc) - \
			vec_dot(oc, cyl->data->axis) * \
			vec_dot(oc, cyl->data->axis) - \
			cyl->data->radius * cyl->data->radius);
}

bool	get_intersection_root(double a, double b, double c, t_hit_rec *hit)
{
	double	disc;
	double	sqrt_disc;
	double	root;

	disc = b * b - 4 * a * c;
	if (disc < 0.0)
		return (false);
	sqrt_disc = sqrt(disc);
	root = (-b - sqrt_disc) / (2 * a);
	if (root < hit->min_t || hit->max_t < root)
	{
		root = (-b + sqrt_disc) / (2 * a);
		if (root < hit->min_t || hit->max_t < root)
			return (false);
	}
	if (root > hit->max_t)
		return (false);
	hit->t = root;
	return (true);
}