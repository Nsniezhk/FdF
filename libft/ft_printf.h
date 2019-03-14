/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:39:53 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/05/07 14:40:16 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "handler.h"
# include "t_arg.h"

int		ft_printf(const char *format, ...);
int		format_processing(const char **format, va_list *args_list);
int		arg_processing(char **format,
		va_list *args_list, t_arg *arg, int *symbs);
char	*flags_check(char **format, t_arg *arg);
char	*width_check(char **format, va_list *args_list, t_arg *arg);
char	*precision_check(char **format, va_list *args_list, t_arg *arg);
char	*length_check(char **format, t_len *len);
#endif
