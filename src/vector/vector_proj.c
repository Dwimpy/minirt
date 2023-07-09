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