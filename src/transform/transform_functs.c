/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_functs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwimpy <dwimpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:39:00 by arobu             #+#    #+#             */
/*   Updated: 2023/05/07 18:56:36 by dwimpy           ###   ########.fr       */
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

t_mat4x4	identity_matrix(void)
{
	return (((t_mat4x4){.mtx = {
				{1.0f, 0.0f, 0.0f, 0.0f},
				{0.0f, 1.0f, 0.0f, 0.0f},
				{0.0f, 0.0f, 1.0f, 0.0f},
				{0.0f, 0.0f, 0.0f, 1.0f},
			}}));
}

t_transform	new_tf(void)
{
	t_transform	transform;

	transform.mat = identity_matrix();
	transform.inv_mat = transform.mat;
	return (transform);
}
