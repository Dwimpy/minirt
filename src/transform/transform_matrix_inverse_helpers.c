/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_matrix_inverse_helpers.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:41:15 by arobu             #+#    #+#             */
/*   Updated: 2023/05/05 21:19:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

double	**create_augumented_matrix(t_mat4x4 mat, size_t order)
{
	size_t		i;
	size_t		j;
	double		**matrix;

	i = 0;
	j = 0;
	matrix = ft_calloc(order, sizeof(*matrix));
	while (i < order)
	{
		j = 0;
		matrix[i] = ft_calloc(2 * order, sizeof(**matrix));
		while (j < 2 * order)
		{
			if (j == i + order)
				matrix[i][j] = 1;
			else if (j < order)
				matrix[i][j] = mat.mtx[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	return (matrix);
}

void	interchange_rows(double **mtx, size_t order)
{
	size_t	i;
	double	*tmp_arr;

	i = order - 1;
	while (i > 0)
	{
		if (mtx[i - 1][0] < mtx[i][0])
		{
			tmp_arr = mtx[i];
			mtx[i] = mtx[i - 1];
			mtx[i - 1] = tmp_arr;
		}
		i--;
	}
}

void	replace_row(double **matrix, size_t order)
{
	size_t	i;
	size_t	j;
	size_t	k;
	double	temp;

	i = -1;
	while (++i < order)
	{
		j = -1;
		while (++j < order)
		{
			k = -1;
			if (j != i)
			{
				if (matrix[i][i] == 0)
					matrix[i][i] = 1e-16;
				temp = matrix[j][i] / (matrix[i][i]);
				while (++k < 2 * order)
				{
					matrix[j][k] -= matrix[i][k] * temp;
				}
			}
		}
	}
}

void	finalize_inverse(double **mtx, size_t order)
{
	size_t	i;
	size_t	j;
	double	tmp;

	i = 0;
	tmp = 0;
	while (i < order)
	{
		tmp = mtx[i][i];
		j = 0;
		while (j < 2 * order)
		{
			mtx[i][j] = mtx[i][j] / tmp;
			j++;
		}
		i++;
	}
}

t_mat4x4	copy_inverse(double **mat, size_t order)
{
	return ((t_mat4x4){
		.mtx = \
		{
			{mat[0][order], mat[0][order + 1], \
			mat[0][order + 2], mat[0][order + 3]},
			{mat[1][order], mat[1][order + 1], \
			mat[1][order + 2], mat[1][order + 3]},
			{mat[2][order], mat[2][order + 1], \
			mat[2][order + 2], mat[2][order + 3]},
			{mat[3][order], mat[3][order + 1], \
			mat[3][order + 2], mat[3][order + 3]},
		}});
}
