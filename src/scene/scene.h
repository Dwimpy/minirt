/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:52:30 by arobu             #+#    #+#             */
/*   Updated: 2023/07/26 20:52:30 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H

# define SCENE_H

# include "camera.h"
# include <stdint.h>

typedef struct s_resolution
{
	uint32_t		width;
	uint32_t		height;
}					t_resolution;

// SPP - samples per pixel
// BPR - bounces per ray

typedef struct s_sampling
{
	double 			spp;
	int 			bpr;
}					t_sampling;

typedef struct s_scene
{
	t_camera		camera;
	t_resolution	resolution;
	t_sampling		sampling;
	t_list			*objects;
}					t_scene;

void	image_create_window(t_image **image, t_scene *scene);
void	scene_add_object(t_scene *scene, void *content);
void	scene_set_resolution(t_scene *scene, uint32_t width, uint32_t height);
void	scene_set_sampling(t_scene *scene, double spp, int bpr);
void	scene_setup_cam(t_scene *scene, t_vec3 pos, t_vec3 orientation, double fov);
void	scene_create_shapes(t_scene *scene);
void	scene_render(t_scene *scene, t_image *image, t_sampler *sampler);
void	scene_clean(t_scene *scene);

#endif
