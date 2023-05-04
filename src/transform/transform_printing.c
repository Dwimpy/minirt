/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:08:07 by arobu             #+#    #+#             */
/*   Updated: 2023/05/04 16:42:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void	print_matrix(t_mat4x4 mat)
{
	int	count;
	int	i;
	int	j;

	count = 15;
	i = 0;
	j = 0;
	while (count >= 0)
	{
		printf("%.3f", mat.mtx[i][j]);
		if (count % 4 == 0)
		{
			j = 0;
			i++;
			printf("\n");
		}
		else
		{
			j++;
			printf("\t");
		}
		count--;
	}
}
