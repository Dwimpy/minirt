/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:12:38 by arobu             #+#    #+#             */
/*   Updated: 2023/05/26 16:12:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
#define TESTER_H

#include "logger.h"
#include "transform.h"
#include "vec3.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define INIT_TEST(type)                                                        \
  type res;                                                                    \
  type ex;                                                                     \
  bool success;                                                                \
                                                                               \
  result->result = ft_calloc(1, sizeof(*res));                                 \
  result->expected = ft_calloc(1, sizeof(*ex));                                \
  res = result->result;                                                        \
  ex = result->expected;

#define DESCRIPTION(string) printf(GREEN("Testing:") " %s\n", string);
#define TEST(expr) *res = expr success = 1;
#define TEST_ASSERT(expr)                                                      \
  expr if (!test_success(vec_equals(*res, *ex))) success = 0;

#define TEST_ASSERT_DOUBLE(expr)                                               \
  expr if (!test_success(equals_precision_um(*res, *ex))) success = 0;

#define TEST_ASSERT_MATRIX(expr)                                               \
  expr if (!test_success(are_matrices_equal(*res, *ex))) success = 0;

#define PRINT_ERROR(test, result)                                              \
  if (success == 0) {                                                          \
    logger(test_error, "-> ");                                                 \
    print_result(test, *result);                                               \
  }

typedef struct s_test_result {
	void *result;
	void *expected;
} t_test_result;

typedef enum e_test_module {
	NONE,
	VECTOR,
	DOUBLE,
	MATRIX
} t_test_module;

typedef struct s_test_case t_test_case;

typedef struct s_test_case {
	char *test_name;
	t_test_module module;

	bool
	(*test_func)(
		t_test_case test,
		t_test_result *result);
} t_test_case;

bool
double_equals(
	double a,
	double b,
	double epsilon);

bool
equals_precision_cm(
	double a,
	double b);

bool
equals_precision_um(
	double a,
	double b);

bool
vec_equals(
	t_vec3 a,
	t_vec3 b);

bool
test_success(
	bool success);

// Tests

bool
run_tests(
	t_test_result *result);

bool
vector_test_add(
	t_test_case test,
	t_test_result *result);

bool
vector_test_zero(
	t_test_case test,
	t_test_result *result);

bool
vector_test_scale(
	t_test_case test,
	t_test_result *result);

bool
vector_test_cross(
	t_test_case test,
	t_test_result *result);

bool
vector_test_normalize(
	t_test_case test,
	t_test_result *result);

bool
vector_test_sub(
	t_test_case test,
	t_test_result *result);

bool
vector_test_magnitude(
	t_test_case test,
	t_test_result *result);

bool
vector_test_mag_squared(
	t_test_case test,
	t_test_result *result);

bool
vector_test_dot(
	t_test_case test,
	t_test_result *result);

bool
transform_test_new(
	t_test_case test,
	t_test_result *result);

bool
transform_test_scale(
	t_test_case test,
	t_test_result *result);

bool
transform_test_translate(
	t_test_case test,
	t_test_result *result);

bool
transform_test_rotate_x(
	t_test_case test,
	t_test_result *result);

bool
transform_test_rotate_y(
	t_test_case test,
	t_test_result *result);

bool
transform_test_rotate_z(
	t_test_case test,
	t_test_result *result);

bool
tf_matrix_test_empty(
	t_test_case test,
	t_test_result *result);

bool
tf_matrix_test_identity(
	t_test_case test,
	t_test_result *result);

bool
tf_matrix_test_inverse(
	t_test_case test,
	t_test_result *result);

bool
tf_matrix_test_multiply(
	t_test_case test,
	t_test_result *result);

void
print_result(
	t_test_case test,
	t_test_result result);

#endif
