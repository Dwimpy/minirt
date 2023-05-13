/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwimpy <dwimpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:45:29 by dwimpy            #+#    #+#             */
/*   Updated: 2023/05/08 13:11:25 by dwimpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_transform	tf_scale(double a, double b, double c)
{
	t_transform	transform;

	transform = new_tf();
	transform.mat.mtx[0][0] = a;
	transform.mat.mtx[1][1] = b;
	transform.mat.mtx[2][2] = c;
	transform.mat.mtx[3][3] = 1.0f;
	transform.inv_mat = matrix_inverse(transform.mat, 4);
	return (transform);
}

t_transform	tf_translate(double dx, double dy, double dz)
{
	t_transform	transform;

	transform = new_tf();
	transform.mat.mtx[0][3] = dx;
	transform.mat.mtx[1][3] = dy;
	transform.mat.mtx[2][3] = dz;
	transform.inv_mat = matrix_inverse(transform.mat, 4);
	return (transform);
}

t_mat4x4	transpose_matrix(t_mat4x4 matrix)
{
	return ((t_mat4x4){
		.mtx =
		{
			{matrix.mtx[0][0], matrix.mtx[1][0], \
				matrix.mtx[2][0], matrix.mtx[3][0]},
			{matrix.mtx[0][1], matrix.mtx[1][1], \
				matrix.mtx[2][1], matrix.mtx[3][1]},
			{matrix.mtx[0][2], matrix.mtx[1][2], \
				matrix.mtx[2][2], matrix.mtx[3][2]},
			{matrix.mtx[0][3], matrix.mtx[1][3], \
				matrix.mtx[2][3], matrix.mtx[3][3]}
		}
		});
}