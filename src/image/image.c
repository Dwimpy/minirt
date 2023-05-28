/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:50:11 by arobu             #+#    #+#             */
/*   Updated: 2023/05/27 21:29:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include <stdlib.h>

t_image	*create_window(size_t w, size_t h, char *title, bool resize)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	image->width = w;
	image->height = h;
	image->title = title;
	image->resizeable = resize;
	image->win = mlx_init(
			image->width, image->height, \
			image->title, image->resizeable
			);
	image->img = mlx_new_image(image->win, image->width, image->height);
	mlx_image_to_window(image->win, image->img, 0, 0);
	return (image);
}

void	set_pixel(t_image *image, t_color color, int i, int j)
{
	mlx_put_pixel(image->img, i, j, \
		get_rgba(color.r * 255, color.g * 255, color.b * 255, 0xFF));

}

void	draw_loop(mlx_t	*win)
{
	mlx_loop(win);
	mlx_terminate(win);
}
