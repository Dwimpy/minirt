/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:56:35 by arobu             #+#    #+#             */
/*   Updated: 2023/05/17 19:41:44 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static const t_test_case	g_tests[] = {
	{"Addition::vec_add", VECTOR, vector_test_add},
	{"VecZero::vec_zero", VECTOR, vector_test_zero},
	{"VecScale::vec_scale", VECTOR, vector_test_scale},
	{"VecCross::vec_cross", VECTOR, vector_test_cross},
	{NULL, NONE, NULL}
};
