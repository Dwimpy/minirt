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

#include "MLX42.h"
#include "camera.h"
#include "cylinder.h"
#include "disk.h"
#include "ft_printf.h"
#include "material.h"
#include "plane.h"
#include "rect.h"
#include "sphere.h"
#include "tests.h"
#include "transform.h"
#include "cuboid.h"
#include "scene.h"
#include <stdio.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024
#define SPP 4.0

int main() {
	t_scene	scene;
	t_image *image;
	t_camera camera;
	t_test_result result;
	t_sphere *sphere;
	t_sphere *sphere2;
	t_sphere *sphere3;
	t_sphere *sphere4;
	t_list *list;
	t_color pc;
	t_sampler *sampler;
	t_cylinder *cyl;
	t_plane *plane;
	t_disk *disk;
	int i;
	int j;
	int k;
	t_list *cur;
	t_rect	*rect;
	t_cuboid	*cuboid;
	sampler = new_sampler(1000);
//	if (!run_tests(&result))
//		return (0);
	image = create_window(1280, 820, "MiniRT", 0);
	scene.camera = cam_setup(
		(t_cam_params) {(t_vec3) {0.0, 505, -20.0}, // Position
						(t_vec3) {0.0, 0.0, 1.0},     // Look-at
						50.0, (double) image->width / (double) image->height});
	init_sampler(sampler, hash(3325));
	sphere = create_sphere(3.0, (t_vec3) {0.0, 505.5, 10.0},
						   lambertian((t_color) {0.7, 0.3, 0.3}));
	sphere2 = create_sphere(500, (t_vec3) {0.0, 0.0, 10.0},
							lambertian((t_color) {0.7, 0.3, 0.3}));
	sphere3 = create_sphere(3.5, (t_vec3) {7.0, 504.0, 9.0},
							metal((t_color) {0.5, 0.5, 0.5}));
	sphere4 = create_sphere(1.5, (t_vec3) {-8.0, 502, 9.0}, glass(1.52));
	plane = create_plane(
		(t_plane_data) {
			(t_vec3) {4.0, 503.5, 10.0},
			(t_vec3) {1.0, 0.0, 0.0},
		},
		lambertian((t_color) {1.0, 0.0, 0.0}));
	disk = create_disk(
		(t_disk_data) {(t_vec3) {4.0, 503.5, 10.0}, (t_vec3) {0.0, 0.0, 1.0}, 3.0},
		lambertian((t_color) {0.0, 0.0, 1.0}));
	cyl = create_cylinder((t_cylinder_data) {(t_vec3) {0.0, 501, 10.0},
											 (t_vec3) {0.0, 1.0, 0.0}, 3.0, 8.0},
						  lambertian((t_color) {0.7, 0.3, 0.3}));
//	vec_print(sphere4->data->center);
	rect = create_rect((t_rect_data){
		(t_vec3){0.0, 504, 1.0},
		(t_vec3){0.0, 0.0, 1.0},
		1.0,
		1.0
	}, lambertian((t_color){0.7, 0.3, 0.3}));
	cuboid = create_cuboid((t_cuboid_data){
		(t_vec3){0.0, 503, 1.0},
		(t_vec3){1.0, 1.0, 0.6},
		4.0,
		2.0,
		4.5
	}, lambertian((t_color){0.7, 0.3, 0.3}));
	list = ft_lstnew(cuboid);
	ft_lstadd_back(&list, ft_lstnew(sphere));
	ft_lstadd_back(&list, ft_lstnew(sphere2));
	ft_lstadd_back(&list, ft_lstnew(sphere3));
	ft_lstadd_back(&list, ft_lstnew(sphere4));
	cam_print(scene.camera);
	i = -1;
	j = -1;
	while (++j < image->height - 1) {
		i = 0;
		while (++i < image->width - 1) {
			k = -1;
			init_sampler(sampler, hash(j * image->width + i));
			pc = color_zero();
			while (++k < SPP) {
				pc = color_add(
					pc, color_scale(1.0 / SPP,
									color_blend(cam_get_ray(&scene.camera, image,
															(t_coords) {(int) i, (int) j},
															sampler),
												list, 6, sampler)));
			}
			set_pixel(image, color_sqrt(pc), i, j);
		}
	}
	while (list) {
		cur = list;
		((t_shape *) (list->content))->shape_info->destroy(list->content);
		list = list->next;
		free(cur);
	}
	draw_loop(image->win);
	destroy_sampler(sampler);
	//	system("leaks minirt");
}

void test_cyl(void) {
	t_hit_rec hit_rec;
	t_ray test;
	t_ray test2;
	t_ray test3;
	t_ray test4;

	test.pos = (t_vec3) {1.0, 0.0, 0.0};
	test.dir = (t_vec3) {0.0, 0.0, 1.0};
	test2.pos = (t_vec3) {0.0, 5.0, -1.0};
	test2.dir = (t_vec3) {0.0, 0.0, 1.0};
	test3.pos = (t_vec3) {0.5, -2.0, 1.0};
	test3.dir = (t_vec3) {0.1, 1.0, 1.0};
	test4.pos = (t_vec3) {-1.0, 1.0, 0.0};
	test4.dir = (t_vec3) {0.1, 1.0, 1.0};
	printf("%d\n", cylinder_hit(NULL, &test, &hit_rec));
	printf("%d\n", cylinder_hit(NULL, &test2, &hit_rec));
	printf("%d\n", cylinder_hit(NULL, &test3, &hit_rec));
	printf("%d\n", cylinder_hit(NULL, &test4, &hit_rec));
}
