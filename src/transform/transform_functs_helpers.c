/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_functs_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:38:16 by arobu             #+#    #+#             */
/*   Updated: 2023/05/15 17:00:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_mat4x4 matrix_empty(void) {
	return ((t_mat4x4) {.mtx = {{0.0f, 0.0f, 0.0f, 0.0f},
								{0.0f, 0.0f, 0.0f, 0.0f},
								{0.0f, 0.0f, 0.0f, 0.0f},
								{0.0f, 0.0f, 0.0f, 0.0f}}});
}

void free_aug_matrix(double **mtx, size_t order) {
	size_t i;

	i = 0;
	while (i < order) {
		free(mtx[i]);
		i++;
	}
	free(mtx);
}
