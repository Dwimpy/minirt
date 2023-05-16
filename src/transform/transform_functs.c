/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_functs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:39:00 by arobu             #+#    #+#             */
/*   Updated: 2023/05/15 16:59:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

double	to_degrees(float radians)
{
	return (radians * (180.0f / M_PI));
}

double	to_radians(float degrees)
{
	return (degrees * M_PI / 180.0f);
}

t_mat4x4	matrix_identity(void)
{
	return (((t_mat4x4){.mtx = {
				{1.0f, 0.0f, 0.0f, 0.0f},
				{0.0f, 1.0f, 0.0f, 0.0f},
				{0.0f, 0.0f, 1.0f, 0.0f},
				{0.0f, 0.0f, 0.0f, 1.0f},
			}}));
}

t_transform	tf_new(void)
{
	t_transform	transform;

	transform.mat = matrix_identity();
	transform.inv_mat = transform.mat;
	return (transform);
}
