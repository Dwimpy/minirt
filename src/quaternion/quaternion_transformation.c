/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_transformation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:09:20 by arobu             #+#    #+#             */
/*   Updated: 2023/05/18 16:16:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"
#include "quaternion.h"
#include <stdio.h>

static t_quaternion
get_quaternion(
	t_conversion_params p);

t_quaternion
eul_to_quat(
	t_euler orientation) {
	t_conversion_params params;

	params.cr = cos(
		orientation.roll *
			0.5);
	params.sr = sin(
		orientation.roll *
			0.5);
	params.cp = cos(
		orientation.pitch *
			0.5);
	params.sp = sin(
		orientation.pitch *
			0.5);
	params.cy = cos(
		orientation.yaw *
			0.5);
	params.sy = sin(
		orientation.yaw *
			0.5);
	return (get_quaternion(
		params));
}

static t_quaternion
get_quaternion(
	t_conversion_params p) {
	t_quaternion quaternion;

	quaternion.w =
		p.cr *
			p.cp *
			p.cy +
			p.sr *
				p.sp *
				p.sy;
	quaternion.x =
		p.sr *
			p.cp *
			p.cy -
			p.cr *
				p.sp *
				p.sy;
	quaternion.y =
		p.cr *
			p.sp *
			p.cy +
			p.sr *
				p.cp *
				p.sy;
	quaternion.z =
		p.cr *
			p.cp *
			p.sy -
			p.sr *
				p.sp *
				p.cy;
	return (quaternion);
}

void
print_quaternion(
	t_quaternion q) {
	logger(debug,
		   "Quat: (w, x, y, z):\t [" WHITE(
			   "%f") "][" WHITE(
			   "%f") "]\
[" WHITE("%f") "][" WHITE(
			   "%f") "]\n",
		   round(q.w),
		   round(q.x),
		   round(q.y),
		   round(q.z));
}
