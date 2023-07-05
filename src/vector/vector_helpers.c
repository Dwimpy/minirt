/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:59:51 by arobu             #+#    #+#             */
/*   Updated: 2023/07/02 21:02:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "tester.h"

t_vec3	vec_reflect(t_vec3 vec, t_vec3 normal)
{
	return (vec_sub(vec, vec_scale(2.0 * vec_dot(vec, normal), normal)));
}

t_vec3	vec_refract(t_vec3 r, t_vec3 normal, double ref_ratio)
{
	double	cos_theta;
	t_vec3	rx;
	t_vec3	ry;

	cos_theta = fmin(vec_dot(vec_scale(-1, r), normal), 1.0);
	rx = vec_scale(ref_ratio, vec_add(r, vec_scale(cos_theta, normal)));
	ry = vec_scale((-1) * sqrt(fabs(1.0 - vec_magnitude_squared(rx))), normal);
	return (vec_add(rx, ry));
}

void	set_vec_comp(t_vec3 *vec, double x, double y, double z)
{
	if (double_equals(x, 0.0, 1e-16))
		x = 1e-16;
	if (double_equals(y, 0.0, 1e-16))
		y = 1e-16;
	if (double_equals(z, 0.0, 1e-16))
		z = 1e-16;
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

double	max(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}

t_vec3	vec3_lin_comb(double alpha, t_vec3 a, double beta, t_vec3 b)
{
	return (vec_add(vec_scale(alpha, a), vec_scale(beta, b)));
}
