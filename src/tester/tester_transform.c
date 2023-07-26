/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:40:29 by arobu             #+#    #+#             */
/*   Updated: 2023/05/19 15:25:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tests.h"

bool	transform_test_scale(
	t_test_case test,
	t_test_result *result)
{
	INIT_TEST(
		t_vec3 *)
	DESCRIPTION(
		"TransformScale")
	set_vec_comp(
		(t_vec3 *)result->result,
		2.0,
		3.0,
		4.0);
	transform_vector(
		(t_vec3 *)result->result,
		tf_scale(
			1.5,
			1.5,
			1.5)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			3.0f,
			4.5f,
			6.0f);)
	set_vec_comp(
		(t_vec3 *)result->result,
		-2.0,
		2.0,
		-2.0);
	transform_vector(
		(t_vec3 *)result->result,
		tf_scale(
			0.5,
			0.5,
			0.5)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			-1.0f,
			1.0f,
			-1.0f);)
	PRINT_ERROR(
		test,
		result)
	set_vec_comp(
		(t_vec3 *)result->result,
		1.0,
		2.0,
		3.0);
	transform_vector(
		(t_vec3 *)result->result,
		tf_scale(
			0.0f,
			0.0f,
			0.0f)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			0.0f,
			0.0f,
			0.0f);)
	PRINT_ERROR(
		test,
		result)
	return (success);
}

bool	transform_test_translate(
	t_test_case test,
	t_test_result *result)
{
	INIT_TEST(
		t_vec3 *)
	DESCRIPTION(
		"TransformTranslate")
	set_vec_comp(
		(t_vec3 *)result->result,
		2.0f,
		3.0f,
		4.0f);
	transform_point(
		(t_vec3 *)result->result,
		tf_translate(
			1.0f,
			1.0f,
			1.0f)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			3.0f,
			4.0f,
			5.0f);)
	PRINT_ERROR(
		test,
		result)
	set_vec_comp(
		(t_vec3 *)result->result,
		-2.0f,
		-2.0f,
		-2.0f);
	transform_point(
		(t_vec3 *)result->result,
		tf_translate(
			-1.0f,
			-1.0f,
			0.5f)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			-3.0f,
			-3.0f,
			-1.5f);)
	PRINT_ERROR(
		test,
		result)
	set_vec_comp(
		(t_vec3 *)result->result,
		1.0f,
		2.0f,
		3.0f);
	transform_point(
		(t_vec3 *)result->result,
		tf_translate(
			0.0f,
			0.0f,
			0.0f)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			1.0f,
			2.0f,
			3.0f);)
	PRINT_ERROR(
		test,
		result)
	return (success);
}

bool	transform_test_rotate_x(
	t_test_case test,
	t_test_result *result)
{
	INIT_TEST(
		t_vec3 *)
	DESCRIPTION(
		"TransformRotateX")
	set_vec_comp(
		(t_vec3 *)result->result,
		1.0f,
		0.0f,
		0.0f);
	transform_point(
		(t_vec3 *)result->result,
		tf_rotate_x(
			M_PI_2)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			1.0f,
			0.0f,
			0.0f);)
	PRINT_ERROR(
		test,
		result)
	set_vec_comp(
		(t_vec3 *)result->result,
		2.0,
		2.0,
		3.0);
	transform_vector(
		(t_vec3 *)result->result,
		tf_rotate_x(
			M_PI_4)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			2.0f,
			-0.70711f,
			3.53553f);)
	PRINT_ERROR(
		test,
		result)
	set_vec_comp(
		(t_vec3 *)result->result,
		2.0,
		2.0,
		2.0);
	transform_vector(
		(t_vec3 *)result->result,
		tf_rotate_x(
			0.0f)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			2.0f,
			2.0f,
			2.0f);)
	PRINT_ERROR(
		test,
		result)
	return (success);
}

bool	transform_test_rotate_y(
	t_test_case test,
	t_test_result *result)
{
	INIT_TEST(
		t_vec3 *)
	DESCRIPTION(
		"TransformRotateY")
	set_vec_comp(
		(t_vec3 *)result->result,
		2.0,
		3.0,
		4.0);
	transform_vector(
		(t_vec3 *)result->result,
		tf_rotate_y(
			M_PI_2)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			4.0f,
			3.0f,
			-2.0f);)
	PRINT_ERROR(
		test,
		result)
	set_vec_comp(
		(t_vec3 *)result->result,
		1.0,
		2.0,
		3.0);
	transform_vector(
		(t_vec3 *)result->result,
		tf_rotate_y(
			M_PI_4)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			2.828427f,
			2.0f,
			1.41214f);)
	PRINT_ERROR(
		test,
		result)
	set_vec_comp(
		(t_vec3 *)result->result,
		2.0,
		2.0,
		2.0);
	transform_vector(
		(t_vec3 *)result->result,
		tf_rotate_y(
			0.0f)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			2.0f,
			2.0f,
			2.0f);)
	PRINT_ERROR(
		test,
		result)
	return (success);
}

bool	transform_test_rotate_z(
	t_test_case test,
	t_test_result *result)
{
	INIT_TEST(
		t_vec3 *)
	DESCRIPTION(
		"TransformRotateZ")
	set_vec_comp(
		(t_vec3 *)result->result,
		2.0,
		3.0,
		4.0);
	transform_vector(
		(t_vec3 *)result->result,
		tf_rotate_z(
			M_PI_2)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			-3.0f,
			2.0f,
			4.0f);)
	PRINT_ERROR(
		test,
		result)
	set_vec_comp(
		(t_vec3 *)result->result,
		1.0,
		2.0,
		3.0);
	transform_vector(
		(t_vec3 *)result->result,
		tf_rotate_z(
			M_PI_4)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			-0.707117f,
			2.12132f,
			3.0f);)
	PRINT_ERROR(
		test,
		result)
	set_vec_comp(
		(t_vec3 *)result->result,
		2.0,
		2.0,
		2.0);
	transform_vector(
		(t_vec3 *)result->result,
		tf_rotate_z(
			0.0f)
			.mat);
	TEST(*(t_vec3 *)result->result;)
	TEST_ASSERT(
		set_vec_comp(
			ex,
			2.0f,
			2.0f,
			2.0f);)
	PRINT_ERROR(
		test,
		result)
	return (success);
}

bool	transform_test_new(
	t_test_case test,
	t_test_result *result)
{
	INIT_TEST(
		t_mat4x4 *)
	DESCRIPTION(
		"TransformNew")
	*(t_mat4x4 *)result->result = tf_new().mat;
	TEST(*(t_mat4x4 *)result->result;)
	TEST_ASSERT_MATRIX(
			*ex = matrix_identity();)
	PRINT_ERROR(
		test,
		result)
	return (success);
}
