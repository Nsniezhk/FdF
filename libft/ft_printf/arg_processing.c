/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:57:19 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/22 19:14:36 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_arg.h"
#include "libft.h"
#include <stdio.h>
#include <stdarg.h>

char		*flags_check(char **format, t_arg *arg)
{
	if (**format == '-' || **format == '+' ||
		**format == ' ' || **format == '#' || **format == '0')
	{
		if (**format == '-')
			arg->has_minus = 1;
		if (**format == '+')
			arg->has_plus = 1;
		if (**format == ' ')
			arg->has_space = 1;
		if (**format == '#')
			arg->has_hash = 1;
		if (**format == '0')
			arg->has_zero = 1;
		if (arg->has_minus)
			arg->has_zero = 0;
		(*format)++;
		return (flags_check(format, arg));
	}
	return (*format);
}

char		*width_check(char **format, va_list *args_list, t_arg *arg)
{
	int arg_width;

	arg->width = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			(*format)++;
			arg_width = va_arg(*args_list, int);
			if (arg_width < 0)
				arg->has_minus = 1;
			arg->width = arg_width < 0 ? -arg_width : arg_width;
			arg->has_width = 1;
		}
		if (ft_isdigit(**format))
		{
			arg->has_width = 1;
			arg->width = 0;
			while (ft_isdigit(**format))
				arg->width = arg->width * 10 + (*(*format)++ - '0');
		}
	}
	return (*format);
}

char		*precision_check(char **format, va_list *args_list, t_arg *arg)
{
	int prec;

	if (**format && **format == '.')
	{
		(*format)++;
		arg->precision = 0;
		if (**format == '*')
		{
			(*format)++;
			if ((prec = va_arg(*args_list, int)) >= 0)
			{
				arg->precision = prec;
				arg->has_precision = 1;
			}
			return (*format);
		}
		else
		{
			while (ft_isdigit(**format))
				arg->precision = arg->precision * 10 + (*(*format)++ - '0');
			arg->has_precision = 1;
			return (*format);
		}
	}
	return (*format);
}

char		*length_check(char **format, t_len *len)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		*len = hh;
		return ((*format) += 2);
	}
	if (**format == 'l' && *(*format + 1) == 'l')
	{
		*len = ll;
		return ((*format) += 2);
	}
	if (**format == 'h' || **format == 'l' ||
		**format == 'j' || **format == 'z')
	{
		if (**format == 'h')
			*len = h;
		if (**format == 'l')
			*len = l;
		if (**format == 'j')
			*len = j;
		if (**format == 'z')
			*len = z;
		return ((*format)++);
	}
	return (*format);
}
