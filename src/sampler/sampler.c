/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:32:17 by arobu             #+#    #+#             */
/*   Updated: 2023/05/28 17:49:00 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sampler.h"
#include <stdlib.h>
#include <stdio.h>

static inline int	is_prime(int num);

t_sampler	*new_sampler(int dim)
{
	t_sampler	*sampler;
	int			prime;
	int			i;

	sampler = (t_sampler *)malloc(sizeof(t_sampler));
	sampler->dim = dim;
	sampler->primes = (int *)malloc(sizeof(int) * dim);
	if (!sampler->primes)
		return (NULL);
	prime = 2;
	i = 0;
	while (i < dim)
	{
		while (!is_prime(prime))
			prime++;
		sampler->primes[i] = prime;
		i++;
		prime++;
	}
	return (sampler);
}

uint32_t	hash(uint32_t x)
{
	x += ~(x << 15);
	x ^= (x >> 10);
	x += (x << 3);
	x ^= (x >> 6);
	x += ~(x << 11);
	x ^= (x >> 16);
	return (x);
}

void	init_sampler(t_sampler	*sampler, uint32_t seed)
{
	sampler->rnd_unit = generate_uniform_number(seed);
	if (sampler->curr_pass == UINT32_MAX)
		sampler->curr_pass = 1;
	if (sampler->curr_prime == INT32_MAX)
		sampler->curr_prime = 0;
	sampler->curr_pass += 1;
	sampler->curr_prime = 0;
}

static inline int	is_prime(int num)
{
	int		i;

	if (num <= 1)
		return (0);
	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

float	generate_uniform_number(uint32_t seed)
{
	t_rnd_params	p;

	p.i = (seed >> 9) | 0x3f800000u;
	return (p.f - 1.0f);
}
