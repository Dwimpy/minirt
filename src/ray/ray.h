/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:58:08 by arobu             #+#    #+#             */
/*   Updated: 2023/05/19 19:12:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct s_ray {
	t_vec3 pos;
	t_vec3 dir;
} t_ray;

t_ray
create_ray(
	t_vec3 pos,
	t_vec3 dir);

t_vec3
value_at(
	t_ray *ray,
	double t);

#endif
