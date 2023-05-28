/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:20:53 by arobu             #+#    #+#             */
/*   Updated: 2023/05/27 13:44:51 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

bool	double_equals(double a, double b, double epsilon)
{
	double	diff;

	diff = a - b;
	if (fabs(diff) > epsilon)
		return (false);
	return (true);
}

bool	equals_precision_cm(double a, double b)
{
	return (double_equals(a, b, 0.01f));
}

bool	equals_precision_um(double a, double b)
{
	return (double_equals(a, b, 0.000005f));
}

bool	vec_equals(t_vec3 a, t_vec3 b)
{
	if (!equals_precision_cm(a.x, b.x) || \
		!equals_precision_cm(a.y, b.y) || \
		!equals_precision_cm(a.z, b.z))
		return (false);
	return (true);
}

bool	test_success(bool success)
{
	if (success)
		return (true);
	return (false);
}
