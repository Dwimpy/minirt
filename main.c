/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:59:49 by arobu             #+#    #+#             */
/*   Updated: 2023/05/19 20:53:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf.h"
#include <stdio.h>
#include "vec3.h"
#include "transform.h"
#include "camera.h"
#include "logger.h"
#include "tests.h"
#include "ray.h"
#include "color.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_camera	camera;
	int			index;
	t_test_result	result;

	t_vec3		a = (t_vec3){.x = 0.0f, .y = 0.0f, .z = 1.0f};
	t_vec3		b = (t_vec3){.x = 2, .y = 1, .z = 1.5};
	camera = cam_new();
	camera.forward = (t_vec3){0.0f, 0.0f, 1.0f};
	camera.right = (t_vec3){1.0f, 0.0f, 0.0f};
	camera.up = (t_vec3){0.0f, 1.0f, 0.0f};
	// cam_print(camera);
	// ft_putendl_fd("-----------------------------------", 1);
	// cam_compute_optics(&camera);
	// cam_print(camera);
	t_mat4x4	mat = {.mtx = {
		{5, 7, 9, 4},
		{4, 3, 8, 3},
		{7, 5, 6, 2},
		{8, 6, 5, 1},
		}};
	t_mat4x4	inverse;
	// transform_vector(&a, matrix_multiply(tf_translate(0,1,1).mat, tf_rotate_x(M_PI).mat));
	// inverse = matrix_inverse(tf_rotate_x(M_PI).mat, 4);
	// vec_print(a);
	// transform_vector(&a, tf_rotate_z(M_PI / 2).mat);
	// transform_vector(&a, matrix_inverse(tf_rotate_x(M_PI).mat, 4));
	// vec_print(a);
	// matrix_print(inverse);
	// transform_vector(&a, tf_rotate_x(M_PI).mat);
	// vec_print(a);
	// transform_vector(&a, tf_translate(5, 5, 5).mat);
	// vec_print(a);
	// vec_print(a);
	t_euler or = (t_euler){0.0f, to_radians(30.0f), 0.0f};
	index = 0;
	run_tests(&result);
	camera.aspect_ratio = 16.0f / 9.0f;
	camera.width = 1200;
	camera.height = camera.width / camera.aspect_ratio;

	double viewport_w = 2.0f;
	double viewport_h = viewport_w / camera.aspect_ratio;
	double focal_len = 1.0f;
	t_vec3	origin = {0.0f, 0.0f, 0.0f};
	t_vec3	horizontal = {viewport_w, 0.0f, 0.0f};
	t_vec3	vertical = {0.0f, viewport_h, 0.0f};
	t_vec3	left_corner = origin;
	size_t	i;
	size_t	j;
	double	u;
	double	v;

	left_corner = vec_sub(origin, vec_scale(0.5, horizontal));
	left_corner = vec_sub(left_corner, vec_scale(0.5, vertical));
	left_corner = vec_sub(left_corner, (t_vec3){0.0f, 0.0f ,focal_len});

	cam_set_location(&camera, (t_vec3) {0.0f, 0.0f, 0.0f});
	cam_set_orientation(&camera, (t_euler){0.0f, 0.0f, 0.0f});
	cam_compute_optics(&camera);
	cam_compute_matrix(&camera);
	mlx = mlx_init(camera.width, camera.height, "MiniRT", true);
	image = mlx_new_image(mlx, camera.width, camera.height);
	i = 0;
	j = 0;
	while (j < camera.height - 1)
	{
		i = 0;
		while (i < camera.width -1)
		{
			u = (double)i / (double)(camera.width - 1);
			v = (double)j / (double)(camera.height - 1);
			t_vec3 pos = vec_zero();
			pos = vec_add(left_corner, vec_scale(u, horizontal));
			pos = vec_add(pos, vec_scale(v, vertical));
			pos = vec_sub(pos, origin);
			pos = vec_scale(-1, pos);
			t_ray ray = create_ray(origin, pos);
			t_color pc = color_blend(ray);
			mlx_put_pixel(image, i, j, get_rgba(pc.r * 255, pc.g * 255, pc.b * 255, 0xFF));
			i++;
		}
		j++;
	}
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
