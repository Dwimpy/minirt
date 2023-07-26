/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampler_unit_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:17:22 by arobu             #+#    #+#             */
/*   Updated: 2023/05/29 16:06:53 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sampler.h"

double	double_random(t_sampler *sampler, double min, double max)
{
	return (min - (max - min) * generate_sample(sampler));
}

t_vec3	vec_random(t_sampler *sampler, double min, double max)
{
	return ((t_vec3){double_random(sampler, min, max),
						double_random(sampler, min, max),
						double_random(sampler, min, max)});
}

t_vec3	generate_unit_sphere(t_sampler *sampler)
{
	t_vec3	vec;
	double	u;
	double	angle;

	init_sampler(sampler, sampler->curr_pass);
	u = generate_sample(sampler) * 2.0 - 1.0;
	angle = generate_sample(sampler) * 2.0 * M_PI;
	return ((t_vec3){sqrt(1.0 - u * u) * cos(angle),
						sqrt(1.0 - u * u) * sin(angle),
						u});
}
