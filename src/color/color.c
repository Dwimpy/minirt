/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:39:08 by arobu             #+#    #+#             */
/*   Updated: 2023/05/19 20:52:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_scale(double scale, t_color color)
{
	return ((t_color) {color.r * scale, color.g * scale, color.b * scale});
}

t_color	color_dot(t_color c1, t_color c2)
{
	return ((t_color){c1.r * c2.r, c1.g * c2.g, c1.b * c2.b});
}

t_color	color_add(t_color c1, t_color c2)
{
	return ((t_color){c1.r + c2.r, c1.g + c2.g, c1.b + c2.b});
}

t_color	color_blend(t_ray ray)
{
	double	t;
	t_vec3	dir_norm;
	t_color	final_color;

	dir_norm = vec_normalize(ray.dir);
	t = 0.5 * ((dir_norm.y) + 1.0f);
	final_color = color_scale(1.0f - t, (t_color){1.0f, 1.0f, 1.0f});
	final_color = color_add(final_color, color_scale(t, (t_color){0.2f, 0.5f, 1.0f}));
	return (final_color);
}

int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
