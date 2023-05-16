/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:36:24 by arobu             #+#    #+#             */
/*   Updated: 2023/05/16 13:46:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H
# include <math.h>
# include "vec3.h"
# include "ft_printf.h"

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

t_mat4x4		matrix_empty(void);
t_mat4x4		matrix_identity(void);
t_mat4x4		matrix_inverse(t_mat4x4 mat, size_t order);
t_mat4x4		matrix_multiply(t_mat4x4 a, t_mat4x4 b);

t_transform		tf_new(void);
t_transform		tf_scale(double a, double b, double c);
t_transform		tf_translate(double dx, double dy, double dz);
t_transform		tf_rotate_x(double radians);
t_transform		tf_rotate_y(double radians);
t_transform		tf_rotate_z(double radians);

void			matrix_print(t_mat4x4 mat);
void			matrix_print_any(double **arr, size_t rows, size_t cols);
void			transform_vector(t_vec3 *vec, t_mat4x4 tf);
void			transform_point(t_vec3 *vec, t_mat4x4 tf);

void			free_aug_matrix(double **mtx, size_t order);

#endif
