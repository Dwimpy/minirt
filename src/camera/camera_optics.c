/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_optics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:07:06 by arobu             #+#    #+#             */
/*   Updated: 2023/05/22 19:40:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	cam_compute_optics(t_camera *cam)
{
	if (!cam)
		return ;
	cam->aspect_ratio = (float)cam->width / (float)cam->height;
	cam->look_at = (t_vec3){0.0f, 0.0f, 1.0f};
	cam->forward = vec_normalize(vec_sub(cam->position, cam->look_at));
	cam->right = vec_cross(cam->forward, g_world_up);
	cam->up = vec_cross(cam->forward, cam->right);
}

void	cam_compute_matrix(t_camera *cam)
{
	t_transform	translate;
	t_transform	rotate;

	translate = tf_translate(-cam->position.x, \
		cam->position.y, cam->position.z);
	rotate = tf_rotate((t_euler){cam->orientation.roll, \
		cam->orientation.pitch, cam->orientation.yaw});
	cam->transformation = tf_new();
	cam->transformation.mat = matrix_multiply(\
		cam->transformation.mat, translate.mat);
	cam->transformation.mat = matrix_multiply(\
		cam->transformation.mat, rotate.mat);
	cam->transformation.inv_mat = matrix_inverse(cam->transformation.mat, 4);
	return ;
}

void	cam_set_location(t_camera *camera, t_vec3 location)
{
	camera->position = location;
}

void	cam_set_orientation(t_camera *camera, t_euler or)
{
	camera->orientation = or;
}
