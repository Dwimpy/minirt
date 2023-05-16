/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:55 by arobu             #+#    #+#             */
/*   Updated: 2023/05/16 15:13:38 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "transform.h"

t_camera	new_camera(void)
{
	t_camera	camera;

	camera.width = 0;
	camera.height = 0;
	camera.look_at = vec_zero();
	camera.forward = vec_zero();
	camera.right = vec_zero();
	camera.up = vec_zero();
	camera.transformation = tf_new();
	camera.aspect_ratio = 0.0f;
	camera.h_fov = 0.0f;
	camera.vertical_fov = 0.0f;
	return (camera);
}
