/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:12:38 by arobu             #+#    #+#             */
/*   Updated: 2023/05/17 20:58:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H
# include <math.h>
# include <stdbool.h>
# include "vec3.h"
# include "logger.h"

# define INIT_TEST \
	t_vec3	*res;\
	t_vec3	*ex;\
	bool	success;\
\
	result->result = ft_calloc(1, sizeof(t_vec3));\
	result->expected = ft_calloc(1, sizeof(t_vec3));\
	res = (t_vec3 *)result->result;\
	ex = (t_vec3 *)result->expected;

# define DESCRIPTION(string) printf(GREEN("Testing:")" %s\n", string);
# define TEST(expr) *res = expr\
		success = 1;
# define TEST_ASSERT(expr) expr \
	if (!test_success(vec_equals(*res, *ex)))\
		success = 0;

# define PRINT_ERROR(test, result)\
	if (success == 0)\
	{\
		logger(test_error, "-> ");\
		print_result(test, *result);\
	}

typedef struct s_test_result
{
	void		*result;
	void		*expected;
}				t_test_result;

typedef enum e_test_module
{
	NONE,
	VECTOR,
}				t_test_module;

typedef struct s_test_case	t_test_case;

typedef struct s_test_case
{
	char				*test_name;
	t_test_module		module;
	bool				(*test_func)(t_test_case test, t_test_result *result);
}					t_test_case;


bool	double_equals(double a, double b, double epsilon);
bool	equals_precision_cm(double a, double b);
bool	equals_precision_um(double a, double b);
bool	vec_equals(t_vec3 a, t_vec3 b);
bool	test_success(bool success);

// Tests

bool	vector_test_add(t_test_case test, t_test_result *result);
bool	vector_test_zero(t_test_case test, t_test_result *result);
bool	vector_test_scale(t_test_case test, t_test_result *result);
bool	vector_test_cross(t_test_case test, t_test_result *result);
void	print_result(t_test_case test, t_test_result result);

#endif
