/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:59:49 by arobu             #+#    #+#             */
/*   Updated: 2023/05/28 17:29:07 by arobu            ###   ########.fr       */
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
#include "sampler.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024
#define SPP	16.0
int	main(void)
{
	t_image			*image;
	t_camera		camera;
	t_test_result	result;
	t_sphere		*sphere;
	t_color			pc;
	t_sampler		*sampler;
	int				i;
	int				j;
	int				k;

	sampler = new_sampler(100);
	// if (!run_tests(&result))
		// return (0);
	image = create_window(1920, 1080, "MiniRT", 0);
	camera = cam_setup((t_cam_params)
		{
			(t_vec3){0.0, 0.0, 0.0},		// Position
			(t_vec3){0.0, 5.0, 4.0},		// Look-at
			30.0,
			(double) image->width / (double) image->height
		});
	sphere = create_sphere(0.5, (t_vec3){0.0, 5.0, 4.0});
	i = -1;
	j = -1;
	k = -1;
	while (++j < image->height - 1)
	{
		i = 0;
		while (++i < image->width - 1)
		{
			k = -1;
			init_sampler(sampler, hash(j * image->width + i));
			pc = color_zero();
			while (++k < SPP)
			{
				pc = color_add(pc, color_scale(1.0 / SPP, \
				color_blend(cam_get_ray(&camera, image, i, j, sampler), sphere)));
			}
			set_pixel(image, pc, i, j);
		}
	}
	sphere->shape.shape_info->destroy(&sphere->shape);
	draw_loop(image->win);
	destroy_sampler(sampler);
	// system("leaks minirt");
	return (0);
}
