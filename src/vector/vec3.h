/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:11:48 by arobu             #+#    #+#             */
/*   Updated: 2023/05/23 12:14:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H
# include <math.h>
# include <stdio.h>
# include "logger.h"

typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

static const t_vec3 g_world_up = (t_vec3){0.0f, 1.0f, 0.0f};

t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_scale(double s, t_vec3 a);
t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);
t_vec3	vec_normalize(const t_vec3 a);
t_vec3	vec_zero(void);

double	vec_magnitude(t_vec3 a);
double	vec_magnitude_squared(t_vec3 a);	
double	vec_dot(t_vec3 a, t_vec3 b);
void	vec_print(t_vec3 a);

void	set_vec_comp(t_vec3 *vec, double x, double y, double z);
#endif
