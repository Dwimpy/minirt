/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:59:51 by arobu             #+#    #+#             */
/*   Updated: 2023/05/27 16:25:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "tester.h"

void	set_vec_comp(t_vec3 *vec, double x, double y, double z)
{
	if (double_equals(x, 0.0, 1e-16))
		x = 1e-16;
	if (double_equals(y, 0.0, 1e-16))
		y = 1e-16;
	if (double_equals(z, 0.0, 1e-16))
		z = 1e-16;
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

double	max(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}
