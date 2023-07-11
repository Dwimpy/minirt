/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:10:34 by arobu             #+#    #+#             */
/*   Updated: 2023/07/12 02:10:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBOID_H
# define CUBOID_H
# include "shape.h"
# include "vec3.h"
typedef struct s_cuboid
{
	t_vec3		center;
	t_vec3		axis;

}				t_cuboid;

#endif