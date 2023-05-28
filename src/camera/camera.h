/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:27:57 by arobu             #+#    #+#             */
/*   Updated: 2023/05/27 20:47:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "vec3.h"
# include "transform.h"
# include "quaternion.h"
# include "ray.h"
# include "image.h"
# include "sampler.h"

typedef struct cam_params
{
	t_vec3		position;
	t_vec3		look_at;
	double		fov;
	double		aspect_ratio;
}				t_cam_params;

typedef struct s_camera
{
	t_vec3		forward;
	t_vec3		up;
	t_vec3		right;
	t_vec3		look_at;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_vec3		left_corner;

	t_vec3		position;
	t_transform	transformation;
	t_euler		orientation;

	float		aspect_ratio;
	float		h_fov;
	float		vertical_fov;
}				t_camera;

t_camera	cam_new(void);
t_camera	cam_setup(t_cam_params params);
t_ray		cam_get_ray(t_camera *cam, t_image *image, int x, int y, t_sampler *sampler);
void		cam_compute_optics(t_camera *camera);
void		cam_print(t_camera camera);
void		cam_set_location(t_camera *camera, t_vec3 location);
void		cam_set_orientation(t_camera *camera, t_euler or);
void		cam_compute_matrix(t_camera *cam);

#endif
