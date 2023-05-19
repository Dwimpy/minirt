/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:27:57 by arobu             #+#    #+#             */
/*   Updated: 2023/05/19 16:09:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "vec3.h"
# include "transform.h"
# include "quaternion.h"

typedef struct s_camera
{
	t_vec3		forward;
	t_vec3		up;
	t_vec3		right;
	t_vec3		look_at;

	t_vec3		position;
	t_transform	transformation;
	t_euler		orientation;

	int			width;
	int			height;
	float		aspect_ratio;
	float		h_fov;
	float		vertical_fov;
}				t_camera;

t_camera	cam_new(void);
void		cam_compute_optics(t_camera *camera);
void		cam_print(t_camera camera);
void		cam_set_location(t_camera *camera, t_vec3 location);
void		cam_set_orientation(t_camera *camera, t_euler or);
void		cam_compute_matrix(t_camera *cam);

#endif
