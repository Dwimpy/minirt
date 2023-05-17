/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:38:21 by arobu             #+#    #+#             */
/*   Updated: 2023/05/17 20:55:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

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
}
