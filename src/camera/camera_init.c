/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:55 by arobu             #+#    #+#             */
/*   Updated: 2023/07/02 22:13:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "transform.h"
#include "sampler.h"

t_camera	cam_new(void)
{
	t_camera	camera;

	camera.look_at = vec_zero();
	camera.forward = vec_zero();
	camera.right = vec_zero();
	camera.up = vec_zero();
	camera.transformation = tf_new();
	camera.orientation = (t_euler){0.0f, 0.0f, 0.0f};
	camera.aspect_ratio = 0.0f;
	camera.h_fov = 0.0f;
	camera.vertical_fov = 0.0f;
	return (camera);
}

t_ray	cam_get_ray(t_camera *cam, t_image *image, int x, int y, t_sampler *sampler)
{
	t_ray	ray;
	t_vec3	pix_x;
	t_vec3	pix_y;
	float	viewport_x;
	float	viewport_y;
	double	rnd_x;
	double	rnd_y;

	ray.pos = vec_zero();
	ray.dir = vec_zero();
	rnd_x = generate_sample(sampler);
	rnd_y = generate_sample(sampler);
	viewport_x = 2.0f * tanf(to_radians(cam->vertical_fov) / 2.0f);
	viewport_y = viewport_x / cam->aspect_ratio;
	pix_x = vec_scale(viewport_x / image->width, cam->right);
	pix_y = vec_scale(viewport_y / image->height, cam->up);
	ray.dir = vec_add(\
		cam->forward, \
		vec_add(\
		vec_scale((double)image->width * 0.5 - x - rnd_x, pix_x), \
		vec_scale((double)image->height * 0.5 - y - rnd_y, pix_y))
			);
	ray.dir = vec_normalize(ray.dir);
	transform_point(&ray.pos, cam->transformation.mat);
	transform_vector(&ray.dir, cam->transformation.mat);
	return (create_ray(ray.pos, ray.dir));
}

void	cam_print(t_camera camera)
{
	printf("Look at: ");
	vec_print(camera.look_at);
	printf("Forward : ");
	vec_print(camera.forward);
	printf("Right: ");
	vec_print(camera.right);
	printf("Up: ");
	vec_print(camera.up);
}
