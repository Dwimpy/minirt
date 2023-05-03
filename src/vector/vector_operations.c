/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:22:02 by arobu             #+#    #+#             */
/*   Updated: 2023/05/03 21:19:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	inline	vec_add(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z});
}

t_vec3	inline	vec_scale(double s, t_vec3 a)
{
	return ((t_vec3){.x = s * a.x, .y = s * a.y, .z = s * a.z});
}

t_vec3	inline	vec_sub(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z});
}

double	inline	vec_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	inline	vec_magnitude(t_vec3 a)
{
	return (sqrt(vec_magnitude_squared(a)));
}
