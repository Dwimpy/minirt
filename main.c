/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:59:49 by arobu             #+#    #+#             */
/*   Updated: 2023/07/12 00:40:14 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "tests.h"
#include "scene.h"
#include <stdio.h>

int main() {
	t_scene	scene;
	t_image *image;
	t_sampler *sampler;
	t_test_result result;

//	if (!run_tests(&result))
//		return (0);
	scene.objects = NULL;
	sampler = new_sampler(1000);
	init_sampler(sampler, hash(3325));
	scene_set_resolution(&scene, 1280, 800);
	scene_set_sampling(&scene, 64.0, 50);
	scene_setup_cam(&scene, (t_vec3) {0.0, 570, 10.0},
					(t_vec3) {0.0, -1.0, 0.0},
					50.0);
	cam_print(scene.camera);
	image_create_window(&image, &scene);
	scene_create_shapes(&scene);
	scene_render(&scene, image, sampler);
	scene_clean(&scene);
	draw_loop(image->win);
	destroy_sampler(sampler);
	system("leaks minirt");
}