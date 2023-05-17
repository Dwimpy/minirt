/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:54:32 by arobu             #+#    #+#             */
/*   Updated: 2023/05/17 21:00:25 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include "ft_printf.h"

bool	vector_test_add(t_test_case test, t_test_result *result)
{
	INIT_TEST
	DESCRIPTION("VecAdd")
	TEST(vec_add((t_vec3){1.0f, 2.0f, 3.0f}, (t_vec3){4.0f, 5.0f, 6.0f});)
	TEST_ASSERT(set_vec_comp(ex, 5.0f, 7.0f, 9.0f);)
	PRINT_ERROR(test, result)
	
	TEST(vec_add((t_vec3){-2.5f, 0.0f, 10.5f}, (t_vec3){1.8f, -3.2f, 2.7f});)
	TEST_ASSERT(set_vec_comp(ex, -0.7f, -3.2f, 13.2f);)
	PRINT_ERROR(test, result)
	return (success);
}

bool	vector_test_zero(t_test_case test, t_test_result *result)
{
	INIT_TEST
	DESCRIPTION("VecZero")
	TEST(vec_zero();)
	TEST_ASSERT(set_vec_comp(ex, 0.0f, 0.0f, 0.0f);)
	return (success);
}

bool	vector_test_scale(t_test_case test, t_test_result *result)
{
	INIT_TEST
	DESCRIPTION("VecScale")
	TEST(vec_scale(2.0f, (t_vec3){1.0f, 2.0f, 3.0f});)
	TEST_ASSERT(set_vec_comp(ex, 2.0f, 4.0f, 6.0f);)
	PRINT_ERROR(test, result)
	
	TEST(vec_scale(-0.5f, (t_vec3){-2.0f, 4.0f, -6.0f});)
	TEST_ASSERT(set_vec_comp(ex, 1.0f, -2.0f, 3.0f);)
	PRINT_ERROR(test, result)
	
	TEST(vec_scale(0.0f, (t_vec3){3.5f, 1.2f, -2.7f});)
	TEST_ASSERT(set_vec_comp(ex, 0.0f, 0.0f, 0.0f);)
	PRINT_ERROR(test, result)

	return (success);
}

bool	vector_test_cross(t_test_case test, t_test_result *result)
{
	INIT_TEST
	DESCRIPTION("VecCross")
	TEST(vec_cross((t_vec3){1.0f, 0.0f, 0.0f}, (t_vec3){0.0f, 1.0f, 0.0f});)
	TEST_ASSERT(set_vec_comp(ex, 0.0f, 0.0f, 1.0f);)
	PRINT_ERROR(test, result)

	TEST(vec_cross((t_vec3){2.0f, 3.0f, 4.0f}, (t_vec3){5.0f, 6.0f, 7.0f});)
	TEST_ASSERT(set_vec_comp(ex, -3.0f, 6.0f, -3.0f);)
	PRINT_ERROR(test, result)

	TEST(vec_cross((t_vec3){2.0f, -1.0f, 3.0f}, (t_vec3){4.0f, 5.0f, -2.0f});)
	TEST_ASSERT(set_vec_comp(ex, -13.0f, 16.0f, 14.0f);)
	PRINT_ERROR(test, result)
	return (success);
}

// bool	testcase1(t_test_result *result)
// {
// 	INIT_TEST
// 	DESCRIPTION("test if vec_add overflows")
// 	TEST(vec_cross((t_vec3){1.0f, 0.0f, 0.0f}, (t_vec3){0.0f, 1.0f, 0.0f});)
// 	ASSERT(set_vec_comp(ex, 0.0f, 0.0f, 1.0f))
// 	return (true);
// }
