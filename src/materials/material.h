/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:12:34 by arobu             #+#    #+#             */
/*   Updated: 2023/07/26 21:17:35 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"
# include "hit_record.h"
# include <stdbool.h>

typedef struct material			t_material;
typedef struct scatter_params	t_scatter_params;
typedef bool					(*t_scatter)\
				(t_scatter_params params, t_sampler *sampler);

typedef enum mat_type
{
	LAMBERTIAN,
	GLASS,
	METAL
}								t_mat_type;

typedef struct material
{
	t_mat_type					type;
	double						refraction_index;
	t_color						albedo;
	t_scatter					scatter;
}								t_material;

typedef struct scatter_params
{
	t_ray						*ray;
	t_hit_rec					*hit;
	t_color						*attenuation;
	t_ray						*scattered;
	double						ref_index;
}								t_scatter_params;

t_material		lambertian(t_color albedo);
t_material		metal(t_color albedo);
t_material		glass(double ref_index);
bool			scatter_lambertian(t_scatter_params params, t_sampler *sampler);
bool			scatter_metal(t_scatter_params, t_sampler *sampler);
bool			scatter_glass(t_scatter_params params, t_sampler *sampler);

#endif
