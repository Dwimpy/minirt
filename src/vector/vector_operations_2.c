/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:38:23 by arobu             #+#    #+#             */
/*   Updated: 2023/05/03 21:26:51 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3 inline	vec_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){.x = a.y * b.z - a.z * b.y, \
					.y = a.z * b.x - a.x * b.z, \
					.z = a.x * b.y - a.y * b.x});
}

t_vec3 inline	vec_normalize(const t_vec3 a)
{
	double	len;

	len = vec_magnitude(a);
	return ((t_vec3){.x = a.x / len, .y = a.y / len, .z = a.z / len});
}

double inline	vec_magnitude_squared(t_vec3 a)
{
	return (vec_dot(a, a));
}

void inline	vec_print(t_vec3 a)
{
	printf("(x, y, z): [%f] [%f] [%f]", a.x, a.y, a.z);
}
