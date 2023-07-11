/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:32:10 by arobu             #+#    #+#             */
/*   Updated: 2023/05/31 17:20:59 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "sampler.h"

static double reflectance(double cosine, double refraction_index);

t_material lambertian(t_color albedo) {
	t_material material;

	material.type = LAMBERTIAN;
	material.albedo = albedo;
	material.scatter = scatter_lambertian;
	material.refraction_index = 0.0;
	return (material);
}

t_material metal(t_color albedo) {
	t_material material;

	material.type = METAL;
	material.albedo = albedo;
	material.scatter = scatter_metal;
	material.refraction_index = 0.0;
	return (material);
}

t_material glass(double ref_index) {
	t_material material;

	material.refraction_index = ref_index;
	material.type = GLASS;
	material.scatter = scatter_glass;
	return (material);
}

bool scatter_lambertian(t_scatter_params params, t_sampler *sampler) {
	t_vec3 scatter_dir;

	scatter_dir = vec_add(params.hit->surf_normal,
						  vec_normalize(generate_unit_sphere(sampler)));
	if (fabs(scatter_dir.x) < M_EPSILON || fabs(scatter_dir.y) < M_EPSILON ||
		fabs(scatter_dir.z) < M_EPSILON)
		scatter_dir = params.hit->surf_normal;
	*params.scattered = create_ray(params.hit->isec_point, scatter_dir);
	*params.attenuation = params.hit->material->albedo;
	return (true);
}

bool scatter_metal(t_scatter_params params, t_sampler *sampler) {
	t_vec3 reflected;

	reflected = vec_reflect(params.ray->dir, params.hit->surf_normal);
	*params.scattered = create_ray(
		params.hit->isec_point,
		vec_add(reflected, vec_scale(0.0, generate_unit_sphere(sampler))));
	*params.attenuation = params.hit->material->albedo;
	return (vec_dot(params.scattered->dir, params.hit->surf_normal) > 0);
}

bool scatter_glass(t_scatter_params params, t_sampler *sampler) {
	t_vec3 reflected;
	double refraction_ratio;
	double c_angle;
	double s_angle;
	t_vec3 norm_dir;
	t_vec3 dir;
	bool cannot_refract;

	*params.attenuation = (t_color) {1.0, 1.0, 1.0};
	if (params.hit->front_face)
		refraction_ratio = 1.0 / params.ref_index;
	else
		refraction_ratio = params.ref_index;
	norm_dir = vec_normalize(params.ray->dir);
	c_angle =
		fmin(vec_dot(vec_scale(-1.0, norm_dir), params.hit->surf_normal), 1.0);
	s_angle = sqrt(1.0 - c_angle * c_angle);
	cannot_refract = (refraction_ratio * s_angle) > 1.0;
	if (cannot_refract ||
		reflectance(c_angle, refraction_ratio) > generate_sample(sampler))
		dir = vec_reflect(norm_dir, params.hit->surf_normal);
	else {
		dir = vec_refract(norm_dir, params.hit->surf_normal, refraction_ratio);
	}
	*params.scattered = create_ray(params.hit->isec_point, dir);
	return (true);
}

static double reflectance(double cosine, double refraction_index) {
	double reflectance;

	reflectance = (1.0 - refraction_index) / (1.0 + refraction_index);
	reflectance = reflectance * reflectance;
	return (reflectance + (1.0 - reflectance) * pow((1.0 - cosine), 5.0));
}
