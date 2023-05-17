/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_optics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:07:06 by arobu             #+#    #+#             */
/*   Updated: 2023/05/16 16:32:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	cam_compute_optics(t_camera *cam)
{
	if (!cam)
		return ;
	cam->aspect_ratio = (float)cam->width / (float)cam->height;
	cam->look_at = (t_vec3){0.0f, 0.0f, 1.0f};
	cam->forward = vec_normalize(cam->look_at);
	cam->right = vec_cross(cam->forward, g_world_up);
	cam->up = vec_cross(cam->forward, cam->right);
}

void	cam_set_location(t_camera *camera, t_vec3 location)
{
	camera->position = location;
}

void	cam_set_orientation(t_camera *camera)
{
	return ;
}
