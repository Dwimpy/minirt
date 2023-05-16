/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:27:57 by arobu             #+#    #+#             */
/*   Updated: 2023/05/16 15:37:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "vec3.h"
# include "transform.h"

typedef struct s_camera
{
	t_vec3		forward;
	t_vec3		up;
	t_vec3		right;
	t_vec3		look_at;

	t_vec3		position;
	t_transform	transformation;

	int			width;
	int			height;
	float		aspect_ratio;
	float		h_fov;
	float		vertical_fov;
}				t_camera;

t_camera	new_camera(void);

#endif
