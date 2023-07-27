/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:05:56 by arobu             #+#    #+#             */
/*   Updated: 2023/07/27 15:05:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include "color.h"
# include "vec3.h"

typedef struct s_texture_vtable
{
	t_color		(*get_color)(void *texture);
}				t_texture_vtable;

typedef struct s_solid_color
{
	t_color 	color;
}				t_solid_color;

typedef struct s_image_texture
{
	unsigned char	*data;
	t_color			color;
}				t_image_texture;

typedef struct s_texture
{
	t_texture_vtable	vtable;
	bool				emits;
	void				*data;
}				t_texture;

t_color		get_solid_color(void *data);
t_color		get_texture_color(t_texture texture);
t_texture	create_solid_color_texture(t_color color, bool emitting);
bool		is_texture_emitting(t_texture texture);


#endif