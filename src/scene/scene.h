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

typedef struct s_sampling
{
	t_resolution	resolution;

}					t_sampling;

typedef struct s_scene
{
	t_camera		camera;
	t_sampling		sampling;
}					t_scene;

#endif
