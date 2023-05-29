/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:59:49 by arobu             #+#    #+#             */
/*   Updated: 2023/05/29 19:21:24 by arobu            ###   ########.fr       */
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
#define SPP	100.0
int	main(void)
{
	t_image			*image;
	t_camera		camera;
	t_test_result	result;
	t_sphere		*sphere;
	t_sphere		*sphere2;
	t_list			*list;
	t_color			pc;
	t_sampler		*sampler;
	int				i;
	int				j;
	int				k;

	sampler = new_sampler(1000);
	// if (!run_tests(&result))
		// return (0);
	image = create_window(800 * 16.0 / 9.0, 800, "MiniRT", 0);
	camera = cam_setup((t_cam_params)
		{
			(t_vec3){0.0, 0.0, 0.0},		// Position
			(t_vec3){0.0, -2.5, 10.0},		// Look-at
			100.0,
			(double) image->width / (double) image->height
		});
	sphere = create_sphere(4.5, (t_vec3){0.0, -4.25, 12.0});
	sphere2 = create_sphere(200, (t_vec3){0.0, -208.0, 10.0});
	list = ft_lstnew(sphere);
	ft_lstadd_back(&list, ft_lstnew(sphere2));
	// vec_print(((t_sphere *)list->content)->data->center);
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
				color_blend(cam_get_ray(&camera, \
				image, i, j, sampler), list, 50, sampler)));
			}
			set_pixel(image, color_sqrt(pc), i, j);
		}
	}
	sphere->shape.shape_info->destroy(&sphere->shape);
	draw_loop(image->win);
	destroy_sampler(sampler);
	// system("leaks minirt");
	return (0);
}
