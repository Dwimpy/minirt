/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:08:41 by arobu             #+#    #+#             */
/*   Updated: 2023/05/20 15:48:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPHERE_H
# define SPHERE_H
# include "vec3.h"
# include "ray.h"

typedef struct s_sphere
{
	t_vec3		center;
	double		radius;
}				t_sphere;

double	hit_sphere(const t_ray ray, t_sphere sphere);

#endif
