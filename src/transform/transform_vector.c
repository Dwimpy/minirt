/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwimpy <dwimpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:57:51 by dwimpy            #+#    #+#             */
/*   Updated: 2023/05/07 19:11:51 by dwimpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

inline void	transform_vector(t_vec3 *vec, t_mat4x4 tf)
{
	t_vec3	tmp;

	tmp.x = (vec->x * tf.mtx[0][0] + vec->y * \
			tf.mtx[0][1] + vec->z * tf.mtx[0][2]);
	tmp.y = (vec->x * tf.mtx[1][0] + vec->y * \
			tf.mtx[1][1] + vec->z * tf.mtx[1][2]);
	tmp.z = (vec->x * tf.mtx[2][0] + vec->y * \
			tf.mtx[2][1] + vec->z * tf.mtx[2][2]);
	*vec = tmp;
}

inline void transform_point(t_vec3 *vec, t_mat4x4 tf)
{
	t_vec3	tmp;

	tmp.x = (vec->x * tf.mtx[0][0] + vec->y * \
			tf.mtx[0][1] + vec->z * tf.mtx[0][2]) + tf.mtx[0][3];
	tmp.y = (vec->x * tf.mtx[1][0] + vec->y * \
			tf.mtx[1][1] + vec->z * tf.mtx[1][2]) + tf.mtx[1][3];
	tmp.z = (vec->x * tf.mtx[2][0] + vec->y * \
			tf.mtx[2][1] + vec->z * tf.mtx[2][2]) + tf.mtx[2][3];
	*vec = tmp;
}