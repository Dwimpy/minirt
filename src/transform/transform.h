/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:36:24 by arobu             #+#    #+#             */
/*   Updated: 2023/05/04 16:31:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H
# include <math.h>
# include "vec3.h"

typedef struct s_mat4x4
{
	double		mtx[4][4];
}				t_mat4x4;

typedef struct s_transform
{
	t_mat4x4	mat;
	t_mat4x4	inv_mat;
}				t_transform;

double			to_degrees(float radians);
double			to_radians(float degrees);

t_mat4x4		identity_matrix(void);
t_mat4x4		matrix_multiply(t_mat4x4 a, t_mat4x4 b);

t_transform		new_transform(void);
t_transform		new_transform_scale(double a, double b, double c);
t_transform		new_transform_rotate_x(double radians);
t_transform		new_transform_rotate_y(double radians);
t_transform		new_transform_rotate_z(double radians);

void			print_matrix(t_mat4x4 mat);
void			transform_vector(t_vec3	*vec, t_mat4x4 tf);

#endif
