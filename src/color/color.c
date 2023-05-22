/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:39:08 by arobu             #+#    #+#             */
/*   Updated: 2023/05/22 16:40:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "sphere.h"

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

t_color	color_blend(t_ray ray, t_sphere *sphere)
{
	double	t;
	t_vec3	dir_norm;
	t_color	final_color;
	double	hit;
	t_vec3	unit_dir;

	hit = sphere->shape.shape_info->hit(&sphere->shape, &ray);
	if (hit > 0.0f)
	{
		unit_dir = vec_normalize(vec_sub(value_at(&ray, hit), (t_vec3){0.0f, 0.0f, 1.0f}));
		return (color_scale(0.5, (t_color){unit_dir.x + 1.0f, unit_dir.y + 1.0f, unit_dir.z + 1.0f}));
	}
	dir_norm = vec_normalize(ray.dir);
	t = 0.5 * ((dir_norm.y) + 1.0f);
	final_color = color_scale(1.0f - t, (t_color){1.0f, 1.0f, 1.0f});
	final_color = color_add(final_color, color_scale(t, (t_color){0.5f, 0.7f, 1.0f}));
	return (final_color);
}

int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
