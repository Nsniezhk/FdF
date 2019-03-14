/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 14:33:31 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/27 14:33:35 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "handler.h"
#include "extenctions.h"

size_t	octal_handler(char **format, va_list *args_list, t_arg *arg)
{
	uintmax_t num;

	if (**format == 'O')
		arg->len = l;
	unsigned_length_processing(&num, args_list, arg);
	if (arg->has_hash && num == 0 && arg->has_precision && arg->precision == 0)
	{
		if (arg->has_width && !arg->has_minus)
			print_space_or_zero(1, arg->width, arg->has_zero ? '0' : ' ');
		ft_putchar('0');
		if (arg->has_width && arg->has_minus)
			print_space_or_zero(1, arg->width, ' ');
		return (arg->has_width ? FT_MAX(arg->width, 1) : 1);
	}
	else if (arg->has_hash && num != 0)
	{
		arg->has_precision = 1;
		arg->precision = FT_MAX(arg->precision, numstr_len(num, 8) + 1);
	}
	return (uint_handler(num, 8, arg, NULL));
}
