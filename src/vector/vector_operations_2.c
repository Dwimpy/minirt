/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:38:23 by arobu             #+#    #+#             */
/*   Updated: 2023/05/18 01:25:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

inline t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){.x = a.y * b.z - a.z * b.y, \
					.y = a.z * b.x - a.x * b.z, \
					.z = a.x * b.y - a.y * b.x});
}

inline t_vec3	vec_zero(void)
{
	return ((t_vec3){.x = 0, .y = 0, .z = 0});
}

inline t_vec3	vec_normalize(const t_vec3 a)
{
	double	len;

	len = vec_magnitude(a);
	if (len == 0)
		len = 1e-16;
	return ((t_vec3){.x = a.x / len, .y = a.y / len, .z = a.z / len});
}

inline double	vec_magnitude_squared(t_vec3 a)
{
	return (vec_dot(a, a));
}

inline void	vec_print(t_vec3 a)
{
	logger(debug, "Vector: (x, y, z):\t ["WHITE("%f")"]\
["WHITE("%f")"]["WHITE("%f")"]", a.x, a.y, a.z);
}
