/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_matrix_multiplication.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:09:00 by arobu             #+#    #+#             */
/*   Updated: 2023/05/04 17:35:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void	fill_mtx_row(t_mat4x4 *dest, int row, t_mat4x4 a, t_mat4x4 b);

t_mat4x4	matrix_multiply(t_mat4x4 a, t_mat4x4 b)
{
	t_mat4x4	mult;

	fill_mtx_row(&mult, 0, a, b);
	fill_mtx_row(&mult, 1, a, b);
	fill_mtx_row(&mult, 2, a, b);
	fill_mtx_row(&mult, 3, a, b);
	return (mult);
}

void	fill_mtx_row(t_mat4x4 *dest, int row, t_mat4x4 a, t_mat4x4 b)
{
	dest->mtx[row][0] = a.mtx[row][0] * b.mtx[0][0] + a.mtx[row][1] * \
	b.mtx[1][0] + a.mtx[row][2] * b.mtx[2][0] + a.mtx[row][3] * b.mtx[3][0];
	dest->mtx[row][1] = a.mtx[row][0] * b.mtx[0][1] + a.mtx[row][1] * \
	b.mtx[1][1] + a.mtx[row][2] * b.mtx[2][1] + a.mtx[row][3] * b.mtx[3][1];
	dest->mtx[row][2] = a.mtx[row][0] * b.mtx[0][2] + a.mtx[row][1] * \
	b.mtx[1][2] + a.mtx[row][2] * b.mtx[2][2] + a.mtx[row][3] * b.mtx[3][2];
	dest->mtx[row][3] = a.mtx[row][0] * b.mtx[0][3] + a.mtx[row][1] * \
	b.mtx[1][3] + a.mtx[row][2] * b.mtx[2][3] + a.mtx[row][3] * b.mtx[3][3];

}
