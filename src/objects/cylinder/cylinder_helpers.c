/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:03:58 by arobu             #+#    #+#             */
/*   Updated: 2023/07/02 21:10:35 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

double get_quadratic_term(t_cylinder *cyl, t_ray *ray)
{
	return ((ray->dir.x * ray->dir.x + \
			ray->dir.y * ray->dir.y + \
			ray->dir.z * ray->dir.z) - \
			(cyl->data->axis.x * cyl->data->axis.x \
			+ cyl->data->axis.y * cyl->data->axis.y \
			+ cyl->data->axis.z * cyl->data->axis.z));
}

double get_linear_term(t_cylinder *cyl, t_ray *ray, t_vec3 oc)
{
	return (2.0 * (ray->dir.x * oc.x + \
				ray->dir.y * oc.y + \
				ray->dir.z * oc.z - \
			(cyl->data->axis.x * oc.x + \
			cyl->data->axis.y * oc.y + \
			cyl->data->axis.z * oc.z)));
}

double get_constant_term(t_cylinder *cyl, t_vec3 oc)
{
	return ((oc.x * oc.x + \
			oc.y * oc.y + \
			oc.z * oc.z) - \
			(cyl->data->axis.x * oc.x + \
			cyl->data->axis.y * oc.y + \
			cyl->data->axis.z * oc.z));
}
