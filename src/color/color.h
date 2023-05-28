/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:30:43 by arobu             #+#    #+#             */
/*   Updated: 2023/05/27 21:22:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "MLX42.h"
# include "ray.h"
# include "sphere.h"

typedef struct s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

t_color	color_zero(void);
t_color	color_scale(double scale, t_color color);
t_color	color_dot(t_color c1, t_color c2);
t_color	color_add(t_color c1, t_color c2);
t_color	color_blend(t_ray ray, t_sphere *sphere);
int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a);;
double	clamp(double x, double min, double max);

#endif
