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
#include "color.h"
#include "transform.h"
#include "sampler.h"
#include "vec3.h"

t_camera	cam_new(void)
{
	t_camera	camera;

	camera.look_at = vec_zero();
	camera.forward = vec_zero();
	camera.right = vec_zero();
	camera.up = vec_zero();
	camera.transformation = tf_new();
	camera.orientation = (t_euler){0.0, 0.0, 0.0};
	camera.aspect_ratio = 0.0;
	camera.h_fov = 0.0;
	camera.vertical_fov = 0.0;
	return (camera);
}

static inline double sign(double v) {
	return (v >= 0.0) ? 1.0 : -1.0;
}

static inline double triangleDistribution(double v) {
	const double orig = v * 2.0 - 1.0;
	v = orig / sqrt(fabs(orig));
	v = clamp(v, -1.0, 1.0); // Clamping it like this might be a bit overkill.
	v = v - sign(orig);
	return v;
}

t_ray	cam_get_ray(t_camera *cam, t_image *image, \
			t_coords pix, t_sampler *sampler)
{
	t_ray	ray;
	t_vec3	pix_x;
	t_vec3	pix_y;
	double	viewport_x;
	double	viewport_y;

	ray.pos = vec_zero();
	ray.dir = vec_zero();
	viewport_x = 2.0 * tan(to_radians(cam->vertical_fov) / 2.0);
	viewport_y = viewport_x / cam->aspect_ratio;
	pix_x = vec_scale(viewport_x / (double)image->width, cam->right);
	pix_y = vec_scale(viewport_y / (double)image->height, cam->up);
	ray.dir = vec_add(\
		cam->forward, \
		vec_add(\
		vec_scale((double)image->width * 0.5 - (int)pix.x + \
			triangleDistribution(generate_sample(sampler)), pix_x), \
		vec_scale((double)image->height * 0.5 - (int)pix.y + \
			triangleDistribution(generate_sample(sampler)), pix_y))
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
