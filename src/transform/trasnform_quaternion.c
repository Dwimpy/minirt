/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trasnform_quaternion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:28:27 by arobu             #+#    #+#             */
/*   Updated: 2023/05/16 17:36:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void	transform_vector_q(t_vec3 *vec, t_quaternion q)
{
	double	q_scale;
	t_vec3	q_vec;
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;

	q_scale = q.w;
	q_vec = (t_vec3){q.x, q.y, q.z};
	x = vec_scale(2.0f * vec_dot(q_vec, *vec), q_vec);
	y = vec_scale(q_scale * q_scale - vec_dot(q_vec, q_vec), *vec);
	z = vec_scale(2.0f * q_scale, vec_cross(q_vec, *vec));
	*vec = vec_add(x, vec_add(y,z));
}
