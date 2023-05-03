/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:36:24 by arobu             #+#    #+#             */
/*   Updated: 2023/05/03 23:01:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H
# define PI 3.141592653589793238

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

t_transform		new_transform(void);
t_transform		new_transform_scale(double a, double b, double c);

#endif
