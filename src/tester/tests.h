/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:56:35 by arobu             #+#    #+#             */
/*   Updated: 2023/05/19 15:07:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static const t_test_case	g_tests[] = {
	{"Addition::vec_add", VECTOR, vector_test_add},
	{"VecZero::vec_zero", VECTOR, vector_test_zero},
	{"VecScale::vec_scale", VECTOR, vector_test_scale},
	{"VecCross::vec_cross", VECTOR, vector_test_cross},
	{"VecNormalize::vec_normalize", VECTOR, vector_test_normalize},
	{"VecSubtract::vec_sub", VECTOR, vector_test_sub},
	{"VecMagnitude::vec_magnitude", DOUBLE, vector_test_magnitude},
	{"VecMagSquared::vec_mag_squared", DOUBLE, vector_test_mag_squared},
	{"VecDot::vec_dot", DOUBLE, vector_test_dot},
	{"Transform::tf_new", MATRIX, transform_test_new},
	{"Transform::tf_scale", VECTOR, transform_test_scale},
	{"Transform::tf_translate", VECTOR, transform_test_translate},
	{"Trasnform::tf_rotate_x", VECTOR, transform_test_rotate_x},
	{"Trasnform::tf_rotate_y", VECTOR, transform_test_rotate_y},
	{"Trasnform::tf_rotate_z", VECTOR, transform_test_rotate_z},
	{"TransformMarix::matrix_empty", MATRIX, tf_matrix_test_empty},
	{"TransformMarix::matrix_identity", MATRIX, tf_matrix_test_identity},
	{"TransformMarix::matrix_inverse", MATRIX, tf_matrix_test_inverse},
	{"TransformMarix::matrix_multiply", MATRIX, tf_matrix_test_multiply},
	{NULL, NONE, NULL}
};
