/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:06:36 by arobu             #+#    #+#             */
/*   Updated: 2023/05/29 13:52:25 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

inline double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

t_color	color_zero(void)
{
	t_color	color;

	color.r = 0.0;
	color.b = 0.0;
	color.g = 0.0;
	return (color);
}

t_color	color_sqrt(t_color color)
{
	return ((t_color){sqrt(color.r), sqrt(color.g), sqrt(color.b)});
}
