/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_matrix_inverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:40:33 by arobu             #+#    #+#             */
/*   Updated: 2023/05/05 20:57:32 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

double		**create_augumented_matrix(t_mat4x4 mat, size_t order);
void		interchange_rows(double **mtx, size_t order);
void		replace_row(double **matrix, size_t order);
void		finalize_inverse(double **mtx, size_t order);
void		free_aug_matrix(double **mtx, size_t order);
t_mat4x4	copy_inverse(double **mat, size_t order);

t_mat4x4	matrix_inverse(t_mat4x4 mat, size_t order)
{
	double		**aug_mtx;
	t_mat4x4	inverse_mtx;

	aug_mtx = create_augumented_matrix(mat, order);
	interchange_rows(aug_mtx, order);
	replace_row(aug_mtx, order);
	print_matrix_any(aug_mtx, order, 2 * order);
	finalize_inverse(aug_mtx, order);
	inverse_mtx = copy_inverse(aug_mtx, order);
	// free_aug_matrix(aug_mtx, order);
	return (inverse_mtx);
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
