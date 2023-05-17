/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:55 by arobu             #+#    #+#             */
/*   Updated: 2023/05/16 17:26:27 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "transform.h"

t_camera	cam_new(void)
{
	t_camera	camera;

	camera.width = 0;
	camera.height = 0;
	camera.look_at = vec_zero();
	camera.forward = vec_zero();
	camera.right = vec_zero();
	camera.up = vec_zero();
	camera.transformation = tf_new();
	camera.orientation = (t_euler){0.0f, 0.0f, 0.0f};
	camera.aspect_ratio = 0.0f;
	camera.h_fov = 0.0f;
	camera.vertical_fov = 0.0f;
	return (camera);
}

void	cam_print(t_camera camera)
{
	printf("Look at: ");
	vec_print(camera.look_at);
	printf("Forward : ");
	vec_print(camera.forward);
	printf("Right: ");
	vec_print(camera.right);
	printf("Up: ");
	vec_print(camera.up);
}
