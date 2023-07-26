/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:01:19 by arobu             #+#    #+#             */
/*   Updated: 2023/07/02 20:31:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_RECORD_H
# define HIT_RECORD_H
# include "ray.h"
# include <stdbool.h>

typedef struct material	t_material;

typedef struct hit_rec
{
	t_vec3				isec_point;
	t_vec3				surf_normal;
	t_material			*material;
	bool				front_face;
	double				min_t;
	double				max_t;
	double				t;
}						t_hit_rec;

t_hit_rec				new_hit_rec(void);
void					set_front_face(t_ray *ray, t_hit_rec *hit);
#endif
