/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:59:49 by arobu             #+#    #+#             */
/*   Updated: 2023/05/16 15:52:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "ft_printf.h"
#include <stdio.h>
#include "vec3.h"
#include "transform.h"
#include "camera.h"

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
	// transform_vector(&a, matrix_multiply(tf_translate(0,1,1).mat, tf_rotate_x(M_PI).mat));
	// inverse = matrix_inverse(tf_rotate_x(M_PI).mat, 4);
	vec_print(a);
	transform_vector(&a, tf_rotate_z(M_PI / 2).mat);
	// transform_vector(&a, matrix_inverse(tf_rotate_x(M_PI).mat, 4));
	// vec_print(a);
	// matrix_print(inverse);
	// transform_vector(&a, tf_rotate_x(M_PI).mat);
	vec_print(a);
	// transform_vector(&a, tf_translate(5, 5, 5).mat);
	// vec_print(a);
	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "MiniRT", true);
	image = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	ft_memset(image->pixels, 0x92, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(int));
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
