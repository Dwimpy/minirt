/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:52:30 by arobu             #+#    #+#             */
/*   Updated: 2023/07/26 20:52:30 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "camera.h"
#include "color.h"
#include "disk.h"
#include "libft.h"
#include "material.h"
#include "plane.h"
#include "cylinder.h"
#include "rect.h"
#include "sphere.h"
#include "cuboid.h"
#include "tester.h"
#include "texture.h"
#include "vec3.h"

void scene_add_object(t_scene *scene, void *content) {
	if (!scene->objects)
		scene->objects = ft_lstnew(content);
	else
		ft_lstadd_back(&scene->objects, ft_lstnew(content));
}

void scene_set_resolution(t_scene *scene, uint32_t width, uint32_t height) {
	scene->resolution.width = width;
	scene->resolution.height = height;
}

void scene_set_sampling(t_scene *scene, double spp, int bpr) {
	scene->sampling.spp = spp;
	scene->sampling.bpr = bpr;
}

void scene_setup_cam(t_scene *scene, t_vec3 pos, t_vec3 orientation, double fov) {
	t_cam_params params;

	params.position = pos;
	if (double_equals(orientation.x, 0, M_EPSILON))
		orientation.x = M_EPSILON;
	if (double_equals(orientation.y, 0, M_EPSILON))
		orientation.y = M_EPSILON;
	if (double_equals(orientation.z, 0, M_EPSILON))
		orientation.z = M_EPSILON;
	params.look_at = orientation;
	params.fov = fov;
	params.aspect_ratio = (double) scene->resolution.width / (double) scene->resolution.height;
	scene->camera = cam_setup(params);
}

void image_create_window(t_image **image, t_scene *scene) {
	*image = create_window(\
    scene->resolution.width, \
    scene->resolution.height, \
    "MiniRT", \
    0);
}

void scene_create_shapes(t_scene *scene) {
	t_sphere *sphere;
	t_sphere *sphere2;
	t_sphere *sphere3;
	t_sphere *sphere4;
	t_cylinder *cyl;
	t_plane *plane;
	t_rect *rect;
	t_cuboid *cuboid;
	t_disk *disk;

	sphere = create_sphere(3.0, (t_vec3) {0.0, 505, 10.0},
						   diffuse_light((t_color) {0.5, 0.4, 0.3}),
						   create_solid_color_texture(color_create(4.0, 4.0, 4.0), true));
	sphere2 = create_sphere(500, (t_vec3) {0.0, 0.0, 10.0},
							lambertian((t_color) {0.1, 0.6, 0.7}),
							create_solid_color_texture(color_create(0.4, 0.3, 0.7), false));
	sphere3 = create_sphere(3.5, (t_vec3) {7.0, 504.0, 9.0},
							metal((t_color) {0.5, 0.5, 0.5}),
							create_solid_color_texture(color_create(0.4, 0.3, 0.7), false));
	sphere4 = create_sphere(1.5, (t_vec3) {-8.0, 509, 9.0}, glass(1.5),
							create_solid_color_texture(color_create(0.4, 0.3, 0.7), false));
//	plane = create_plane(
//		(t_plane_data) {
//			(t_vec3) {4.0, 503.5, 10.0},
//			(t_vec3) {1.0, 0.0, 0.0},
//		},
//		lambertian((t_color) {1.0, 0.0, 0.0}));
//	disk = create_disk(
//		(t_disk_data) {(t_vec3) {4.0, 503.5, 10.0}, (t_vec3) {0.0, 0.0, 1.0}, 3.0},
//		lambertian((t_color) {0.0, 0.0, 1.0}));
//	cyl = create_cylinder((t_cylinder_data) {(t_vec3) {0.0, 501, 10.0},
//											 (t_vec3) {0.0, 1.0, 0.0}, 3.0, 8.0},
//						  lambertian((t_color) {0.7, 0.3, 0.3}));
////	vec_print(sphere4->data->center);
//	rect = create_rect((t_rect_data){
//		(t_vec3){0.0, 504, 1.0},
//		(t_vec3){0.0, 0.0, 1.0},
//		1.0,
//		1.0
//	}, lambertian((t_color){0.7, 0.3, 0.3}));
	cuboid = create_cuboid((t_cuboid_data) {
		(t_vec3) {0.0, 503, 1.0},
		(t_vec3) {1.0, 1.0, 0.6},
		4.0,
		2.0,
		4.5
	}, lambertian((t_color) {0.7, 0.3, 0.3}));
//	scene_add_object(scene, cuboid);
	scene_add_object(scene, sphere);
	scene_add_object(scene, sphere2);
	scene_add_object(scene, sphere3);
	scene_add_object(scene, sphere4);
}

void scene_render(t_scene *scene, t_image *image, t_sampler *sampler) {
	int i;
	int j;
	int k;
	t_color pc;

	i = -1;
	j = -1;
	while (++j < image->height - 1) {
		i = 0;
		printf("Rendering: %.2f%%\n", (double) j / image->height * 100);
		while (++i < image->width - 1) {
			k = -1;
			init_sampler(sampler, hash(j * image->width + i));
			pc = color_zero();
			while (++k < (int) scene->sampling.spp) {
				pc = color_add(
					pc,
					color_blend(cam_get_ray(&scene->camera, image,
											(t_coords) {(int) i, (int) j},
											sampler),
								scene->objects, scene->sampling.bpr, sampler));
			}
			if (pc.r != pc.r)
				pc.r = 0.0;
			if (pc.g != pc.g)
				pc.g = 0.0;
			if (pc.b != pc.b)
				pc.b = 0.0;
			double scale = 1.0 / scene->sampling.spp;
			pc.r = sqrt(scale * pc.r);
			pc.g = sqrt(scale * pc.g);
			pc.b = sqrt(scale * pc.b);
			set_pixel(image, pc, i, j);
		}
	}
}

void scene_clean(t_scene *scene)
{
	t_list	*cur;

	while (scene->objects)
	{
		cur = scene->objects;
		((t_shape *) (scene->objects->content))->shape_info->destroy(scene->objects->content);
		scene->objects = scene->objects->next;
		free(cur);
	}
}