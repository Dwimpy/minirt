/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:38:21 by arobu             #+#    #+#             */
/*   Updated: 2023/05/26 16:12:51 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

bool	run_tests(t_test_result *result)
{
	size_t	index;
	bool	success;

	index = 0;
	success = 1;
	while (g_tests[index].test_name)
	{
		if (!g_tests[index].test_func(g_tests[index], result))
			success = 0;
		free(result->result);
		free(result->expected);
		result->result = NULL;
		result->expected = NULL;
		index++;
	}
	return (success);
}

void	print_result(t_test_case test, t_test_result result)
{
	if (test.module == VECTOR)
	{
		logger(regular, ""RED("Got:")" [%f][%f][%f] \
"GREEN("Expected:")" [%f][%f][%f]\n", ((t_vec3 *)result.result)->x, \
	((t_vec3 *)result.result)->y, ((t_vec3 *)result.result)->z, \
	((t_vec3 *)result.expected)->x, ((t_vec3 *)result.expected)->y, \
	((t_vec3 *)result.expected)->z);
	}
	else if (test.module == DOUBLE)
	{
		logger(regular, RED("Got:")"[%f] \
"GREEN("Expected:")" [%f]\n", (*(double *)result.result), *(double *)result.expected);
	}
	else if (test.module == MATRIX)
	{
		logger(regular, RED("Got:\n"));
		matrix_print(((t_transform *)result.result)->mat);
		logger(regular, GREEN("Expected:\n"));
		matrix_print(((t_transform *)result.expected)->mat);
// [%f]\n", (*(double *)result.result), *(double *)result.expected);
	}
}
