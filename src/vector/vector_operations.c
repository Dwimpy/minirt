/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:22:02 by arobu             #+#    #+#             */
/*   Updated: 2023/05/17 18:55:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

inline t_vec3 vec_add(t_vec3 a, t_vec3 b) {
	return ((t_vec3) {.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z});
}

inline t_vec3 vec_scale(double s, t_vec3 a) {
	return ((t_vec3) {.x = s * a.x, .y = s * a.y, .z = s * a.z});
}

inline t_vec3 vec_sub(t_vec3 a, t_vec3 b) {
	return ((t_vec3) {.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z});
}

inline double vec_dot(t_vec3 a, t_vec3 b) {
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline double vec_magnitude(t_vec3 a) {
	return (sqrt(vec_magnitude_squared(a)));
}
