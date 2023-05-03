/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_functs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:39:00 by arobu             #+#    #+#             */
/*   Updated: 2023/05/03 23:00:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

double	to_degrees(float radians)
{
	return (radians * (180.0f / PI));
}

double	to_radians(float degrees)
{
	return (degrees * PI / 180.0f);
}

t_mat4x4	identity_matrix(void)
{
	return (((t_mat4x4){.mtx = {
				{1.0f, 0.0f, 0.0f, 0.0f},
				{0.0f, 1.0f, 0.0f, 0.0f},
				{0.0f, 0.0f, 1.0f, 0.0f},
				{0.0f, 0.0f, 0.0f, 0.0f},
			}}));
}

t_transform	new_transform(void)
{
	t_transform	transform;

	transform.mat = identity_matrix();
	transform.inv_mat = transform.mat;
	return (transform);
}

t_transform	new_transform_scale(double a, double b, double c)
{
	t_transform	transform;

	transform = new_transform();
	transform.mat.mtx[0][0] = a;
	transform.mat.mtx[1][1] = b;
	transform.mat.mtx[2][2] = c;
	transform.mat.mtx[3][3] = 1.0f;
	return (transform);
}
