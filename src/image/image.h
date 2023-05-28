/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:42:04 by arobu             #+#    #+#             */
/*   Updated: 2023/05/27 21:29:25 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "MLX42.h"
# include "color.h"
# include <stdlib.h>

typedef struct image
{
	mlx_t		*win;
	mlx_image_t	*img;
	size_t		width;
	size_t		height;
	char		*title;
	bool		resizeable;
}				t_image;

t_image		*create_window(size_t w, size_t h, char *title, bool resize);
void		set_pixel(t_image *image, t_color color, int i, int j);
void		draw_loop(mlx_t	*win);

#endif
