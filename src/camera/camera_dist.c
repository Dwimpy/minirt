/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_dist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:43:08 by arobu             #+#    #+#             */
/*   Updated: 2023/07/09 18:43:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static inline double	sign(double v)
{
	if (v >= 0.0)
		return (1.0);
	return (-1.0);
}

static inline double	triangle_dist(double v)
{
	double		value;

	value = v * 2.0 - 1.0;
	v = value / sqrt(fabs(value));
	v = clamp(v, -1.0, 1.0);
	return (v - sign(value));
}