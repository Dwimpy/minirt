/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampler_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:36:42 by arobu             #+#    #+#             */
/*   Updated: 2023/05/28 17:24:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sampler.h"

static inline double	min(double a, double b);
static inline double	wrap_around(float a, float b);
static inline double	radical_inverse(int pass, int base);

double	generate_sample(t_sampler *sampler)
{
	double	sample;

	sample = wrap_around(
		radical_inverse(sampler->curr_pass,
						sampler->primes[sampler->curr_prime++ % sampler->dim]),
		sampler->rnd_unit);
	return (sample);
}

static inline double	wrap_around(float a, float b)
{
	if (a + b < 1.0f)
		return (a + b);
	else
		return (a + b - 1.0f);
}

static inline double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

static inline double	radical_inverse(int pass, int base)
{
	double	res;
	double	inv_base;
	double	fraction;

	res = 0.0;
	inv_base = 1.0 / base;
	fraction = inv_base;
	while (pass > 0)
	{
		res += (pass % base) * fraction;
		pass /= base;
		fraction *= inv_base;
	}
	return (min(res, 0.999999));
}

void	destroy_sampler(t_sampler *sampler)
{
	if (sampler)
	{
		free(sampler->primes);
		free(sampler);
	}
}
