/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:58:03 by arobu             #+#    #+#             */
/*   Updated: 2023/07/03 15:15:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "hit_record.h"
#include "libft.h"
#include "ray.h"
#include "shape.h"
#include "transform.h"
#include "vec3.h"

static void intersect_tube_quadratic(t_shape *shape, t_ray *ray, double abc[3]);

t_cylinder *create_cylinder(t_cylinder_data data, t_material material) {
	t_shape_info *cyl_info;
	t_cylinder *cylinder;
	t_cylinder_data *cyl_data;


	cyl_info = shape_type_create((t_shape_info) {
			cylinder_get_name_override,
			cylinder_hit,
			cylinder_destroy_override
	});
	cylinder = (t_cylinder *) shape_create(cyl_info);
	cyl_data = (t_cylinder_data *) ft_calloc(1, sizeof(t_cylinder_data));
	*cyl_data = data;
	cylinder->data = cyl_data;
	cylinder->shape.shape_data = (t_cylinder_data *) cyl_data;
	cylinder->shape.material = material;
	return (cylinder);
}

bool cylinder_hit(t_shape *shape, t_ray *ray, t_hit_rec *hit) {

	return (true);
}
