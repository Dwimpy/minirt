/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:10:16 by arobu             #+#    #+#             */
/*   Updated: 2023/07/26 21:14:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	create_ray(t_vec3 pos, t_vec3 dir)
{
	t_ray	ray;

	ray.dir = dir;
	ray.pos = pos;
	return (ray);
}

t_vec3	value_at(t_ray *ray, double t)
{
	return (vec_add(ray->pos, vec_scale(t, ray->dir)));
}
