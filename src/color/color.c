/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:39:08 by arobu             #+#    #+#             */
/*   Updated: 2023/07/26 21:40:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "libft.h"
#include "sphere.h"
#include "texture.h"

t_color color_scale(double scale, t_color color) {
	return ((t_color) {color.r * scale, color.g * scale, color.b * scale});
}

t_color color_dot(t_color c1, t_color c2) {
	return ((t_color) {c1.r * c2.r, c1.g * c2.g, c1.b * c2.b});
}

t_color color_add(t_color c1, t_color c2) {
	return ((t_color) {c1.r + c2.r, c1.g + c2.g, c1.b + c2.b});
}

t_color color_blend(t_ray ray, t_list *list, int depth, t_sampler *sampler) {
	double t;
	t_vec3 dir_norm;
	t_color final_color;
	t_hit_rec hit_rec;
	t_list *tmp;
	int hit_anything;
	t_ray scattered;
	t_color attenuation;
	t_color emitted;

	if (depth <= 0)
		return (color_create(0.0, 0.0, 0.0));
	tmp = list;
	hit_anything = 0;
	hit_rec = new_hit_rec();
	while (tmp) {
		if ((((t_shape *) tmp->content)->shape_info->hit((t_shape *) tmp->content,
														 &ray, &hit_rec)))
			hit_anything = 1;
		tmp = tmp->next;
	}
	if (!hit_anything)
		return (color_create(0.0, 0.0, 0.0));
	scattered.dir = vec_zero();
	scattered.pos = vec_zero();
	if (is_texture_emitting(*hit_rec.texture))
		emitted = get_texture_color(*hit_rec.texture);
	else
		emitted = color_create(0.0, 0.0, 0.0);
	if ((hit_rec.material->scatter((t_scatter_params){&ray, &hit_rec,
				&attenuation, &scattered,
				hit_rec.material->refraction_index}, sampler)))
		return (color_add(emitted, color_dot(attenuation, \
			color_blend(scattered, list, depth - 1, sampler))));
	return (emitted);
}

int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
