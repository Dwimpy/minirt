/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:06:36 by arobu             #+#    #+#             */
/*   Updated: 2023/07/26 21:40:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_zero(void)
{
	t_color	color;

	color.r = M_EPSILON;
	color.b = M_EPSILON;
	color.g = M_EPSILON;
	return (color);
}

t_color	color_sqrt(t_color color)
{
	return ((t_color){sqrt(color.r), sqrt(color.g), sqrt(color.b)});
}

t_color		color_create(double r, double g, double b)
{
	return ((t_color){r, g, b});
}