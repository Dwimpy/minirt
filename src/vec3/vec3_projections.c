/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_proj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:21:05 by arobu             #+#    #+#             */
/*   Updated: 2023/07/09 18:21:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec_project(t_vec3 vector, t_vec3 axis)
{
	t_vec3	projection;
	double	magnitude_squared;

	magnitude_squared = vec_magnitude_squared(axis);
	if (magnitude_squared < M_EPSILON)
		return (vec_zero());
	projection = vec_scale(vec_dot(vector, axis) / magnitude_squared, axis);
	return (projection);
}

inline double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

void	vec3_compute_uv_axes(t_vec3 axis, t_vec3 *u, t_vec3 *v)
{
	t_vec3 orthogonal_vector;

	if (fabs(axis.x) < fabs(axis.y))
		orthogonal_vector = (t_vec3){1.0, 0.0, 0.0};
	else
		orthogonal_vector = (t_vec3){0.0, 1.0, 0.0};
	orthogonal_vector = vec_normalize(orthogonal_vector);
	*u = vec_normalize(vec_cross(axis, orthogonal_vector));
	*v = vec_normalize(vec_cross(axis, *u));
}