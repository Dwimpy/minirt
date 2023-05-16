/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:54:40 by arobu             #+#    #+#             */
/*   Updated: 2023/05/16 15:51:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

inline t_transform	tf_rotate_x(double radians)
{
	t_transform	transform;
	double		cosine;
	double		sine;

	cosine = cos(radians);
	sine = sin(radians);
	transform = tf_new();
	transform.mat.mtx[0][0] = 1.0f;
	transform.mat.mtx[1][1] = cosine;
	transform.mat.mtx[1][2] = round(-sine);
	transform.mat.mtx[2][1] = sine;
	transform.mat.mtx[2][2] = cosine;
	transform.mat.mtx[3][3] = 1.0f;
	transform.inv_mat = matrix_inverse(transform.mat, 4);
	return (transform);
}

inline t_transform	tf_rotate_y(double radians)
{
	t_transform	transform;
	double		cosine;
	double		sine;

	cosine = cos(radians);
	sine = sin(radians);
	transform = tf_new();
	transform.mat.mtx[0][0] = cosine;
	transform.mat.mtx[0][2] = sine;
	transform.mat.mtx[1][1] = 1.0f;
	transform.mat.mtx[2][0] = round(-sine);
	transform.mat.mtx[2][2] = cosine;
	transform.mat.mtx[3][3] = 1.0f;
	transform.inv_mat = matrix_inverse(transform.mat, 4);
	return (transform);
}

inline t_transform	tf_rotate_z(double radians)
{
	t_transform	transform;
	double		cosine;
	double		sine;

	cosine = cos(radians);
	sine = sin(radians);
	transform = tf_new();
	transform.mat.mtx[0][0] = cosine;
	transform.mat.mtx[0][1] = round(-sine);
	transform.mat.mtx[1][0] = sine;
	transform.mat.mtx[1][1] = cosine;
	transform.mat.mtx[2][2] = 1.0f;
	transform.mat.mtx[3][3] = 1.0f;
	transform.inv_mat = matrix_inverse(transform.mat, 4);
	return (transform);
}

