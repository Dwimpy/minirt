/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:59:49 by arobu             #+#    #+#             */
/*   Updated: 2023/05/05 21:20:02 by arobu            ###   ########.fr       */
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
	t_vec3		a = (t_vec3){.x = 3, .y = 2, .z = 4};
	t_vec3		b = (t_vec3){.x = 2, .y = 1, .z = 1.5};
	t_mat4x4	mat = {.mtx = {
		{5, 7, 9, 4},
		{4, 3, 8, 3},
		{7, 5, 6, 2},
		{8, 6, 5, 1},
		}};
	t_mat4x4	inverse;
	printf("x: [%f]\t", vec_add(a, b).x);
	printf("y: [%f]\t", vec_add(a, b).y);
	printf("z: [%f]\n", vec_add(a, b).z);
	printf("x: [%f]\t", vec_cross(a, b).x);
	printf("y: [%f]\t", vec_cross(a, b).y);
	printf("z: [%f]\n", vec_cross(a, b).z);
	printf("Mag: [%f]\n", vec_magnitude(a));
	printf("Mag: [%f]\n", vec_magnitude_squared(a));
	printf("M[1][1]: [%f]\n", identity_matrix().mtx[1][1]);
	vec_print(a);
	// transform_vector(&a, matrix_multiply(tf_rotate_y(M_PI_2).mat, tf_rotate_x(M_PI_2).mat));
	print_matrix(tf_rotate_y(M_PI).mat);
	inverse = matrix_inverse(tf_rotate_x(M_PI).mat, 4);
	tf_vector(&a, inverse);
	vec_print(a);
	// print_matrix(inverse);
	tf_vector(&a, tf_rotate_x(M_PI).mat);
	vec_print(a);
	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "MiniRT", true);
	image = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	ft_memset(image->pixels, 0x92, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(int));
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
