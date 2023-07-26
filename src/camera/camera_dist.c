/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_dist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:43:08 by arobu             #+#    #+#             */
/*   Updated: 2023/07/26 21:21:32 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

inline double	sign(double v)
{
	if (v >= 0.0)
		return (1.0);
	return (-1.0);
}

inline double	triangle_dist(double v)
{
	double	value;

	value = v * 2.0 - 1.0;
	v = value / sqrt(fabs(value));
	v = clamp(v, -1.0, 1.0);
	return (v - sign(value));
}
