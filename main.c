/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:59:49 by arobu             #+#    #+#             */
/*   Updated: 2023/05/23 18:13:00 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "ft_printf.h"
#include <stdio.h>
#include "vec3.h"
#include "transform.h"
#include "camera.h"
#include "logger.h"
#include "tests.h"
#include "ray.h"
#include "color.h"
#include "sphere.h"
#include "image.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

int	main(void)
{
	t_image			*image;
	t_camera		camera;
	t_test_result	result;

	camera = cam_new();
	image = create_window(1920, 1080, "MiniRT", 0);
	// run_tests(&result);
	camera.aspect_ratio = ((float)image->width / (float)image->height);
	camera.width = image->width;
	camera.height = image->width / camera.aspect_ratio;
	cam_set_location(&camera, (t_vec3){0.0f, 0.0f, 0.0f});
	cam_set_orientation(&camera, (t_euler){to_radians(-25.0f), to_radians(0.0f), 0.0f});
	cam_compute_matrix(&camera);
	double viewport_w = 2.0f;
	cam_compute_optics(&camera);
	double viewport_h = viewport_w / camera.aspect_ratio;
	double focus_distance = 10.0f;
	t_vec3	horizontal = vec_scale(focus_distance, vec_scale(viewport_w, camera.right));
	t_vec3	vertical = vec_scale(focus_distance, vec_scale(viewport_h, camera.up));

	t_vec3	left_corner;
	size_t	i;
	size_t	j;
	t_sphere	*sphere;
	double	u;
	double	v;

	sphere = create_sphere(0.5, (t_vec3){0.0f, 0.0f, 10.0f});
	left_corner = vec_sub(camera.position, vec_scale(0.5, horizontal));
	left_corner = vec_sub(left_corner, vec_scale(0.5, vertical));
	left_corner = vec_sub(left_corner, vec_scale(focus_distance, camera.forward));
	transform_vector(&sphere->data->center, camera.transformation.inv_mat);
	vec_print(sphere->data->center);
	i = 0;
	j = 0;
	while (j < image->height - 1)
	{
		i = 0;
		while (i < image->width - 1)
		{
			u = (double)i / (double)(camera.width - 1);
			v = (double)j / (double)(camera.height - 1);
			t_vec3 pos = vec_zero();
			pos = vec_add(left_corner, vec_scale(u, horizontal));
			pos = vec_add(pos, vec_scale(v, vertical));
			pos = vec_sub(pos, camera.position);
			t_ray ray = create_ray(camera.position, pos);
			t_color pc = color_blend(ray, sphere);
			// t_color	pc2 = color_blend(ray, &sphere2);
			// pc = color_add(pc, pc2);
			mlx_put_pixel(image->img, i, j, get_rgba(pc.r * 255, pc.g * 255, pc.b * 255, 0xFF));
			i++;
		}
		j++;
	}
	sphere->shape.shape_info->destroy(&sphere->shape);
	draw_loop(image->win);
	// system("leaks minirt");
	return (0);
}

// int	main(void)
// {
// 	t_image			*image;
// 	t_camera		camera;
// 	t_sphere		*sphere;
// 	t_test_result	result;
// 	double			u;
// 	double			v;
// 	int				i;
// 	int				j;

// 	image = create_window(1920, 1080, "MiniRT", 0);
// 	// run_tests(&result);
// 	camera = set_camera((t_cam_params){
// 		{0.0f, 0.0f, 0.0f}, 
// 		{0.0f, 0.0f, -1.0f},
// 		90.0f,
// 		16.0f / 9.0f
// 		});
// 	sphere = create_sphere(0.5, (t_vec3){0.0f, 0.0f, 10.0f});

// 	transform_vector(&sphere->data->center, camera.transformation.inv_mat);
// 	i = 0;
// 	j = 0;
// 	while (j < image->height - 1)
// 	{
// 		i = 0;
// 		while (i < image->width - 1)
// 		{
// 			u = (double)i / (double)(image->width - 1);
// 			v = (double)j / (double)(image->height - 1);
// 			t_color pc = color_blend(get_ray(&camera, u, v), sphere);
// 			mlx_put_pixel(image->img, i, j, get_rgba(pc.r * 255, pc.g * 255, pc.b * 255, 0xFF));
// 			i++;
// 		}
// 		j++;
// 	}
// 	sphere->shape.shape_info->destroy(&sphere->shape);
// 	draw_loop(image->win);
// 	// system("leaks minirt");
// 	return (0);
// }
