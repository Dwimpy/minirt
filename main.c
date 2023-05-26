/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:59:49 by arobu             #+#    #+#             */
/*   Updated: 2023/05/26 22:25:23 by arobu            ###   ########.fr       */
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
	t_sphere		*sphere;
	t_color			pc;
	int				i;
	int				j;

	if (!run_tests(&result))
		return (0);
	image = create_window(1920, 1080, "MiniRT", 0);
	camera = cam_setup((t_cam_params){
			(t_vec3){0.0, 0.0, 0.0},		// Position
			(t_vec3){0.0, 0.0, 1.0},		// Look-at
			150.0,
			(double) image->width / (double) image->height
		});
	sphere = create_sphere(0.5, (t_vec3){0.0, 0.0, 5.0});
	vec_print(sphere->data->center);
	cam_print(camera);
	i = -1;
	j = -1;
	while (++j < image->height - 1)
	{
		i = 0;
		while (++i < image->width - 1)
		{
			pc = color_blend(cam_get_ray(&camera, image, i, j), sphere);
			mlx_put_pixel(image->img, i, j, get_rgba(pc.r * 255, pc.g * 255, pc.b * 255, 0xFF));
		}
	}
	sphere->shape.shape_info->destroy(&sphere->shape);
	draw_loop(image->win);
	// system("leaks minirt");
	return (0);
}
