/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trasnform_quaternion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:28:27 by arobu             #+#    #+#             */
/*   Updated: 2023/05/26 22:09:54 by arobu            ###   ########.fr       */
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
	x = vec_scale(2.0 * vec_dot(q_vec, *vec), q_vec);
	y = vec_scale(q_scale * q_scale - vec_dot(q_vec, q_vec), *vec);
	z = vec_scale(2.0 * q_scale, vec_cross(q_vec, *vec));
	*vec = vec_add(x, vec_add(y,z));
}

t_mat4x4	quat_to_mat(t_quaternion q)
{
	const double	sq_qw = q.w * q.w;
	const double	sq_qx = q.x * q.x;
	const double	sq_qy = q.y * q.y;
	const double	sq_qz = q.z * q.z;
	t_mat4x4		mat;
	double			invs;

	mat = matrix_identity();
	invs = 1.0 / (sq_qx + sq_qy + sq_qz + sq_qw);
	mat.mtx[0][0] = (sq_qx - sq_qy - sq_qz + sq_qw) * invs;
	mat.mtx[1][1] = (-sq_qx + sq_qy - sq_qz + sq_qw) * invs;
	mat.mtx[2][2] = (-sq_qx - sq_qy + sq_qz + sq_qw) * invs;
	mat.mtx[0][1] = 2.0 * (q.x * q.y - q.z * q.w) * invs;
	mat.mtx[0][2] = 2.0 * (q.x * q.z + q.y * q.w) * invs;
	mat.mtx[1][0] = 2.0 * (q.x * q.y + q.z * q.w) * invs;
	mat.mtx[1][2] = 2.0 * (q.y * q.z - q.x * q.w) * invs;
	mat.mtx[2][0] = 2.0 * (q.x * q.z - q.y * q.w) * invs;
	mat.mtx[2][1] = 2.0 * (q.y * q.z - q.x * q.w) * invs;
	return (mat);
}
	// mtx.mtx[1][0] = 2.0f * ((q.x * q.y) + (q.z * q.w)) * invs;
	// mtx.mtx[0][1] = 2.0f * ((q.x * q.y) - (q.z * q.w)) * invs;
	// mtx.mtx[2][0] = 2.0f * ((q.x * q.z) - (q.y * q.w)) * invs;
	// mtx.mtx[0][2] = 2.0f * ((q.x * q.z) + (q.y * q.w)) * invs;
	// mtx.mtx[2][1] = 2.0f * ((q.y * q.z) + (q.x * q.w)) * invs;
	// mtx.mtx[1][2] = 2.0f * ((q.y * q.z) - (q.x * q.w)) * invs;







