/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_optics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:07:06 by arobu             #+#    #+#             */
/*   Updated: 2023/05/28 16:20:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tester.h"
#include "transform.h"

void
cam_compute_optics(
	t_camera *cam) {
	double viewport_w;
	double viewport_h;
	double focus_distance;

	if (!cam)
		return;
	viewport_w = 2.0;
	viewport_h =
		viewport_w /
			cam->aspect_ratio;
	cam->forward = vec_normalize(
		cam->look_at);
	cam->right = vec_normalize(
		vec_cross(
			g_world_up,
			cam->look_at));
	cam->up = vec_cross(
		cam->look_at,
		cam->right);
}

t_camera
cam_setup(
	t_cam_params params) {
	t_camera cam;

	cam = cam_new();
	cam.aspect_ratio = params.aspect_ratio;
	cam.vertical_fov = params.fov;
	if (double_equals(
		cam.look_at.x,
		0.0,
		M_EPSILON))
		cam.look_at.x = M_EPSILON;
	if (double_equals(
		cam.look_at.y,
		0.0,
		M_EPSILON))
		cam.look_at.y = M_EPSILON;
	if (double_equals(
		cam.look_at.z,
		0.0,
		M_EPSILON))
		cam.look_at.z = M_EPSILON;
	set_vec_comp(
		&cam.look_at,
		params.look_at.x,
		params.look_at.y,
		params.look_at.z);
	cam_set_location(
		&cam,
		params.position);
	cam_set_orientation(
		&cam,
		(t_euler) {
			to_radians(
				0.0),
			to_radians(
				0.0),
			to_radians(
				0.0)});
	cam_compute_matrix(
		&cam);
	cam_compute_optics(
		&cam);
	return (cam);
}

void
cam_compute_matrix(
	t_camera *cam) {
	t_transform translate;
	t_transform rotate;

	translate = tf_translate(
		-cam->position.x,
		cam->position.y,
		cam->position.z);
	rotate = tf_rotate(
		(t_euler) {
			cam->orientation.roll,
			cam->orientation.pitch,
			cam->orientation.yaw});
	cam->transformation = tf_new();
	cam->transformation.mat =
		matrix_multiply(
			cam->transformation.mat,
			translate.mat);
	cam->transformation.mat =
		matrix_multiply(
			cam->transformation.mat,
			rotate.mat);
	cam->transformation.inv_mat = matrix_inverse(
		cam->transformation.mat,
		4);
}

void
cam_set_location(
	t_camera *camera,
	t_vec3 location) {
	camera->position = location;
}

void
cam_set_orientation(
	t_camera *camera,
	t_euler or) {
	camera->orientation = or;
}
