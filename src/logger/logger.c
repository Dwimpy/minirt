/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:06:48 by arobu             #+#    #+#             */
/*   Updated: 2023/05/17 15:20:32 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void
print_log_type(
	t_logtype type) {
	if (type ==
		regular)
		return;
	else if (
		type ==
			info)
		printf("%sInfo: %s",
			   LOG_COLOR_GREEN,
			   LOG_COLOR_WHITE);
	else if (
		type ==
			debug)
		printf("%sDebug: %s",
			   LOG_COLOR_BLUE,
			   LOG_COLOR_WHITE);
	else if (
		type ==
			error)
		printf("%sDebug: %s",
			   LOG_COLOR_RED,
			   LOG_COLOR_WHITE);
	else if (
		type ==
			test_error)
		printf("%sFailed: %s",
			   LOG_COLOR_RED,
			   LOG_COLOR_WHITE);
}

void
logger(t_logtype type,
	   const char *fmt,
	   ...) {
	va_list va_list;
	char buffer[4096];
	int len;

	len = 0;
	print_log_type(
		type);
	va_start(
		va_list,
		fmt);
	len += vsnprintf(
		buffer,
		sizeof(buffer),
		fmt,
		va_list);
	va_end(va_list);
	printf("%s",
		   buffer);
	if (len >
		4096)
		printf("Buffer Overflowed!\n");
	if (type ==
		error) {
		printf("An error occured\n");
		exit(1);
	}
}
