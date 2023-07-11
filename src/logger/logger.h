/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:04:30 by arobu             #+#    #+#             */
/*   Updated: 2023/05/17 18:50:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
#define LOGGER_H

#define LOG_NO_COLOR "\e[0;30m"
#define LOG_COLOR_RED "\e[1;91m"
#define LOG_COLOR_GREEN "\e[1;92m"
#define LOG_COLOR_YELLOW "\e[1;93m"
#define LOG_COLOR_BLUE "\e[1;94m"
#define LOG_COLOR_MAGENTA "\e[1;95m"
#define LOG_COLOR_CYAN "\e[1;96m"
#define LOG_COLOR_WHITE "\e[0;97m"

#define WHITE(string) "\e[0;30m" string "\e[0;97m"
#define RED(string) "\e[0;31m" string "\e[0;97m"
#define GREEN(string) "\e[0;32m" string "\e[0;97m"
#define MAGENTA(string) "\e[0;35m" string "\e[0;97m"

#define LOG_BG_COLOR_RED "\e[0;101m"
#define LOG_BG_COLOR_GREEN "\e[0;102m"
#define LOG_BG_COLOR_YELLOW "\e[0;103m"

typedef enum e_logtype {
	regular,
	info,
	debug,
	test_error,
	error
} t_logtype;

void
logger(t_logtype type,
	   const char *fmt,
	   ...);

#endif
