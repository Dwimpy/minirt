/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:56:35 by arobu             #+#    #+#             */
/*   Updated: 2023/05/18 02:23:20 by arobu            ###   ########.fr       */
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
	{NULL, NONE, NULL}
};
