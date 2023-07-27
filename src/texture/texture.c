/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:05:57 by arobu             #+#    #+#             */
/*   Updated: 2023/07/27 15:05:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "color.h"

t_color get_solid_color(void *data)
{
	t_solid_color	*solid_color;

	solid_color = (t_solid_color *)data;
	return (solid_color->color);
}

t_texture create_solid_color_texture(t_color color, bool emitting)
{
	t_texture		texture;
	t_solid_color	*solid_color;

	texture.vtable.get_color = get_solid_color;
	solid_color = (t_solid_color *)malloc(sizeof(t_solid_color));
	solid_color->color = color;
	texture.data = solid_color;
	texture.emits = emitting;
	return (texture);
}


t_color get_texture_color(t_texture texture)
{
	return (texture.vtable.get_color(texture.data));
}

bool	is_texture_emitting(t_texture texture)
{
	return (texture.emits);
}