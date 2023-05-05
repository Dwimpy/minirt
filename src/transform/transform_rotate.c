/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:54:40 by arobu             #+#    #+#             */
/*   Updated: 2023/05/05 20:54:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_transform	inline	tf_rotate_z(double radians)
{
	t_transform	transform;
	double		cosine;
	double		sine;

	cosine = cos(radians);
	sine = sin(radians);
	transform = new_tf();
	transform.mat.mtx[0][0] = 1.0f;
	transform.mat.mtx[1][1] = cosine;
	transform.mat.mtx[1][2] = round(-sine);
	transform.mat.mtx[2][1] = sine;
	transform.mat.mtx[2][2] = cosine;
	transform.mat.mtx[3][3] = 1.0f;
	return (transform);
}

t_transform inline	tf_rotate_y(double radians)
{
	t_transform	transform;
	double		cosine;
	double		sine;

	cosine = cos(radians);
	sine = sin(radians);
	transform = new_tf();
	transform.mat.mtx[0][0] = cosine;
	transform.mat.mtx[0][2] = sine;
	transform.mat.mtx[1][1] = 1.0f;
	transform.mat.mtx[2][0] = round(-sine);
	transform.mat.mtx[2][2] = cosine;
	transform.mat.mtx[3][3] = 1.0f;
	return (transform);
}

t_transform inline	tf_rotate_x(double radians)
{
	t_transform	transform;
	double		cosine;
	double		sine;

	cosine = cos(radians);
	sine = sin(radians);
	transform = new_tf();
	transform.mat.mtx[0][0] = cosine;
	transform.mat.mtx[0][1] = round(-sine);
	transform.mat.mtx[1][0] = sine;
	transform.mat.mtx[1][1] = cosine;
	transform.mat.mtx[2][2] = 1.0f;
	transform.mat.mtx[3][3] = 1.0f;
	return (transform);
}

void inline	tf_vector(t_vec3 *vec, t_mat4x4 tf)
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
