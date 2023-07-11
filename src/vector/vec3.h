/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:11:48 by arobu             #+#    #+#             */
/*   Updated: 2023/07/02 21:00:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
#define VEC3_H
#define M_EPSILON __DBL_EPSILON__

#include "logger.h"
#include <math.h>
#include <stdio.h>

typedef struct s_coords {
	double x;
	double y;
} t_coords;

typedef struct s_vec3 {
	double x;
	double y;
	double z;
} t_vec3;

static const t_vec3 g_world_up = (t_vec3) {
	0.0,
	1.0,
	0.0};

t_vec3
vec_add(t_vec3 a,
		t_vec3 b);

t_vec3
vec_scale(
	double s,
	t_vec3 a);

t_vec3
vec_sub(t_vec3 a,
		t_vec3 b);

t_vec3
vec_cross(
	t_vec3 a,
	t_vec3 b);

t_vec3
vec_normalize(
	t_vec3 a);

t_vec3
vec_zero(
	void);

t_vec3
vec_reflect(
	t_vec3 vec,
	t_vec3 normal);

t_vec3
vec_refract(
	t_vec3 r,
	t_vec3 n,
	double ref_ratio);

t_vec3
vec_project(
	t_vec3 vector,
	t_vec3 axis);

double
clamp(double x,
	  double min,
	  double max);

double
vec_magnitude(
	t_vec3 a);

double
vec_magnitude_squared(
	t_vec3 a);

double
vec_dot(t_vec3 a,
		t_vec3 b);

double
max(double a,
	double b);

void
vec_print(
	t_vec3 a);

void
set_vec_comp(
	t_vec3 *vec,
	double x,
	double y,
	double z);

#endif
