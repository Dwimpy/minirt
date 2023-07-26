/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:04:41 by arobu             #+#    #+#             */
/*   Updated: 2023/07/26 21:34:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H
# include <math.h>

typedef struct s_quaternion
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_quaternion;

typedef struct s_euler
{
	double		roll;
	double		pitch;
	double		yaw;
}				t_euler;

typedef struct s_conversion_params
{
	double		cr;
	double		sr;
	double		cp;
	double		sp;
	double		cy;
	double		sy;
}				t_conversion_params;

t_quaternion	eul_to_quat(t_euler orientation);
t_euler			eul_orient(double roll, double pitch, double yaw);
t_euler			eul_cam_orient(t_euler camera_or);
void			print_quaternion(t_quaternion q);
#endif
