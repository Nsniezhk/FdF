/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:57:53 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/05/01 12:10:11 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_printf.h"

int		arg_processing(char **format, va_list *args_list,
		t_arg *arg, int *symbs)
{
	t_handler	handler;

	if ((*(++*format)) == '\0')
		return (0);
	if ((flags_check(format, &(*arg))) == NULL)
		return (-1);
	if ((width_check(format, args_list, &(*arg)) == NULL))
		return (-1);
	if ((precision_check(format, args_list, &(*arg))) == NULL)
		return (-1);
	if ((length_check(format, &arg->len)) == NULL)
		return (-1);
	if (**format == '\0')
		return (0);
	if (define_handler(**format) == NULL)
		handler = null_handler;
	else
		handler = define_handler(**format);
	*symbs += (int)handler(format, args_list, arg);
	(*format)++;
	return (1);
}

int		format_processing(const char **format, va_list *args_list)
{
	t_arg	arg;
	int		symbs;

	symbs = 0;
	while (1)
	{
		if (**format == '%')
		{
			ft_bzero(&arg, sizeof(t_arg));
			if ((arg_processing((char**)format, args_list, &arg, &symbs)) == -1)
				return (-1);
		}
		if (**format == '\0')
			return (symbs);
		else if (**format != '\0' && **format != '%')
		{
			write(1, &(**format), 1);
			symbs++;
			if ((*(++*format)) == '\0')
				return (symbs);
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	args_list;
	int		symbs_print;

	va_start(args_list, format);
	symbs_print = format_processing(&format, &args_list);
	va_end(args_list);
	return (symbs_print);
}
