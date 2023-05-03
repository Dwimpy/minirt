/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:59:49 by arobu             #+#    #+#             */
/*   Updated: 2023/05/03 23:00:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf.h"
#include <stdio.h>
#include "vec3.h"
#include "transform.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_vec3		a = (t_vec3){.x = 5, .y = 1, .z = 1.5};
	t_vec3		b = (t_vec3){.x = 2, .y = 1, .z = 1.5};

	printf("x: [%f]\t", vec_add(a, b).x);
	printf("y: [%f]\t", vec_add(a, b).y);
	printf("z: [%f]\n", vec_add(a, b).z);
	printf("x: [%f]\t", vec_cross(a, b).x);
	printf("y: [%f]\t", vec_cross(a, b).y);
	printf("z: [%f]\n", vec_cross(a, b).z);
	printf("Mag: [%f]\n", vec_magnitude(a));
	printf("Mag: [%f]\n", vec_magnitude_squared(a));
	printf("M[1][1]: [%f]\n", identity_matrix().mtx[1][1]);
	vec_print(vec_normalize(a));
	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "MiniRT", true);
	image = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	ft_memset(image->pixels, 0x92, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(int));
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
