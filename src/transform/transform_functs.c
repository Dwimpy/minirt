/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_functs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:39:00 by arobu             #+#    #+#             */
/*   Updated: 2023/05/19 14:22:47 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "tester.h"
#include <stdbool.h>

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

int	are_matrices_equal(t_mat4x4 a, t_mat4x4 b)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!equals_precision_um(a.mtx[i][j], b.mtx[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
