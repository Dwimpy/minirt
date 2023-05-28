/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:12:11 by arobu             #+#    #+#             */
/*   Updated: 2023/05/28 17:43:35 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLER_H
# define SAMPLER_H
#include <stdlib.h>

typedef union u_rnd_params
{
	uint32_t	i;
	float		f;
}			t_rnd_params;

typedef struct sampler
{
	int				dim;
	int				*primes;
	double			rnd_unit;
	unsigned int	curr_pass;
	int				curr_prime;
}			t_sampler;

t_sampler	*new_sampler(int dim);
uint32_t	hash(uint32_t x);
void		init_sampler(t_sampler	*sampler, uint32_t seed);
double		generate_sample(t_sampler *sampler);
float		convert_to_triangle(float n);
float		generate_uniform_number(uint32_t seed);
void		destroy_sampler(t_sampler *sampler);

#endif
