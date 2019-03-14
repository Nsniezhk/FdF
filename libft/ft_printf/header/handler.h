/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:38:38 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/05/07 14:39:00 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H
# include "t_arg.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

size_t		percent_handler(char **format, va_list *args_list, t_arg *arg);
size_t		uint_handler(uintmax_t num, int base, t_arg *arg, char *sign);
size_t		char_handler(char **format, va_list *args_list, t_arg *arg);
size_t		wchar_handler(char **format, va_list *args_list, t_arg *arg);
size_t		wstr_handler(char **format, va_list *args_list, t_arg *arg);
size_t		str_handler(char **format, va_list *args_list, t_arg *arg);
size_t		int_handler(char **format, va_list *args_list, t_arg *arg);
size_t		octal_handler(char **format, va_list *args_list, t_arg *arg);
size_t		hex_handler(char **format, va_list *args_list, t_arg *arg);
size_t		ptr_handler(char **format, va_list *args_list, t_arg *arg);
size_t		unsigned_handler(char **format, va_list *args_list, t_arg *arg);
size_t		null_handler(char **format, va_list *args_list, t_arg *arg);

typedef	size_t	(*t_handler) (char**, va_list*, t_arg*);
t_handler	define_handler(char c);
#endif
