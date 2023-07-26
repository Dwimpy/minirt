/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_transform_matrix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:11:32 by arobu             #+#    #+#             */
/*   Updated: 2023/05/19 15:10:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void
set_matrix_values(
	t_mat4x4 *mat,
	t_mat4x4 new);

bool	tf_matrix_test_empty(
	t_test_case test,
	t_test_result *result)
{
	INIT_TEST(
		t_mat4x4 *)
	DESCRIPTION(
		"TransformMatrixEmpty")
	*(t_mat4x4 *)result->result = matrix_empty();
	TEST(*(t_mat4x4 *)result->result;)
	TEST_ASSERT_MATRIX(
		set_matrix_values(
			ex,
			(t_mat4x4){.mtx = {{0.0f, 0.0f, 0.0f, 0.0f},
								{0.0f, 0.0f, 0.0f, 0.0f},
								{0.0f, 0.0f, 0.0f, 0.0f},
								{0.0f, 0.0f, 0.0f, 0.0f}}});)
	PRINT_ERROR(
		test,
		result)
	return (success);
}

bool	tf_matrix_test_identity(
	t_test_case test,
	t_test_result *result)
{
	INIT_TEST(
		t_mat4x4 *)
	DESCRIPTION(
		"TransformMatrixIdentity")
	*(t_mat4x4 *)result->result = matrix_identity();
	TEST(*(t_mat4x4 *)result->result;)
	TEST_ASSERT_MATRIX(
		set_matrix_values(
			ex,
			(t_mat4x4){.mtx = {{1.0f, 0.0f, 0.0f, 0.0f},
								{0.0f, 1.0f, 0.0f, 0.0f},
								{0.0f, 0.0f, 1.0f, 0.0f},
								{0.0f, 0.0f, 0.0f, 1.0f}}});)
	PRINT_ERROR(
		test,
		result)
	return (success);
}

bool	tf_matrix_test_inverse(
	t_test_case test,
	t_test_result *result)
{
	INIT_TEST(
		t_mat4x4 *)
	DESCRIPTION(
		"TransformMatrixInverse")
	set_matrix_values(
		(t_mat4x4 *)result->result,
		(t_mat4x4){.mtx = {
						{1.0f, 3.0f, 5.0f, 9.0f},
						{1.0f, 3.0f, 1.0f, 7.0f},
						{4.0f, 3.0f, 9.0f, 7.0f},
						{5.0f, 2.0f, 0.0f, 9.0f},
					}});
	*(t_mat4x4 *)result->result = matrix_inverse(
		*(t_mat4x4 *)result->result,
		4);
	TEST(*(t_mat4x4 *)result->result;)
	TEST_ASSERT_MATRIX(
		set_matrix_values(
			ex,
			(t_mat4x4){.mtx = {{-13.0f /
									47.0f,
								2.0f /
									47.0f,
								7.0f /
									47.0f,
								6.0f /
									47.0f},
								{-5.0f /
									8.0f,
								7.0f /
									8.0f,
								1.0f /
									4.0f,
								-1.0f /
									4.0f},
								{39.0f /
									376.0f,
								-53.0f /
									376.0f,
								13.0f /
									188.0f,
								-9.0f /
									188.0f},
								{55.0f /
									188.0f,
								-41.0f /
									188.0f,
								-13.0f /
									94.0f,
								9.0f /
									94.0f}}});)
	PRINT_ERROR(
		test,
		result)
	return (success);
}

bool	tf_matrix_test_multiply(
	t_test_case test,
	t_test_result *result)
{
	INIT_TEST(
		t_mat4x4 *)
	DESCRIPTION(
		"TransformMatrixMultiply")
	set_matrix_values(
		(t_mat4x4 *)result->result,
		matrix_multiply(
			(t_mat4x4){.mtx = {{1.0f, 3.0f, 5.0f, 9.0f},
								{1.0f, 3.0f, 1.0f, 7.0f},
								{4.0f, 3.0f, 9.0f, 7.0f},
								{5.0f, 2.0f, 0.0f, 9.0f}}},
			(t_mat4x4){.mtx = {{1.0f, 3.0f, 5.0f, 9.0f},
								{1.0f, 3.0f, 1.0f, 7.0f},
								{4.0f, 3.0f, 9.0f, 7.0f},
								{5.0f, 2.0f, 0.0f, 9.0f}}}));
	TEST(*(t_mat4x4 *)result->result;)
	TEST_ASSERT_MATRIX(
		set_matrix_values(
			ex,
			(t_mat4x4){.mtx = {
							{69.0f, 45.0f, 53.0f, 146.0f},
							{43.0f, 29.0f, 17.0f, 100.0f},
							{78.0f, 62.0f, 104.0f, 183.0f},
							{52.0f, 39.0f, 27.0f, 140.0f},
						}});)
	PRINT_ERROR(
		test,
		result)
	return (success);
}

static void
set_matrix_values(
	t_mat4x4 *mat,
	t_mat4x4 new)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <
			4)
	{
		j = 0;
		while (j <
				4)
		{
			mat->mtx[i][j] = new.mtx[i][j];
			j++;
		}
		i++;
	}
	return ;
}
