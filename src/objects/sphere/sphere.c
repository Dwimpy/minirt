/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:23:07 by arobu             #+#    #+#             */
/*   Updated: 2023/05/20 19:23:38 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	
#include "sphere.h"
#include <math.h>

double	hit_sphere(const t_ray ray, t_sphere sphere)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	disc;

	oc = vec_sub(ray.pos, sphere.center);
	a = vec_dot(ray.dir, ray.dir);
	half_b = vec_dot(oc, ray.dir);
	c = vec_magnitude_squared(oc) - sphere.radius * sphere.radius;
	disc = half_b * half_b - a * c;
	if (disc < 0)
		return (-1.0f);
	else
		return ((((-1) * half_b) - sqrt(disc)) / (a));
}
