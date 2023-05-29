/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:22:54 by arobu             #+#    #+#             */
/*   Updated: 2023/05/29 19:13:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_record.h"
#include <limits.h>

t_hit_rec	new_hit_rec(void)
{
	t_hit_rec	rec;

	rec.isec_point = vec_zero();
	rec.min_t = 0.000001;
	rec.max_t = __DBL_MAX__;
	rec.surf_normal = vec_zero();
	rec.front_face = 0;
	rec.t = __DBL_MAX__;
	return (rec);
}

void	set_front_face(t_ray *ray, t_hit_rec *hit)
{
	if (vec_dot(ray->dir, hit->surf_normal) < 0)
	{
		hit->surf_normal = vec_scale(1, hit->surf_normal);
		hit->front_face = true;
	}
	else
	{
		hit->surf_normal = vec_scale(-1, hit->surf_normal);
		hit->front_face = false;
	}
}

