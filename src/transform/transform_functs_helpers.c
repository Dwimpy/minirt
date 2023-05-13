/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwimpy <dwimpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:38:16 by arobu             #+#    #+#             */
/*   Updated: 2023/05/07 14:10:06 by dwimpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_mat4x4	empty_matrix(void)
{
	return ((t_mat4x4){
		.mtx = \
		{
			{0.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 0.0f}
		}
	});
}

void	free_aug_matrix(double **mtx, size_t order)
{
	size_t	i;

	i = 0;
	while (i < order)
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}
