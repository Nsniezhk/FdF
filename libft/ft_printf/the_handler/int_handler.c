/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:58:36 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/22 18:45:11 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extenctions.h"
#include "handler.h"

size_t	int_handler(char **format, va_list *arg_list, t_arg *arg)
{
	intmax_t	num;
	char		*sign;

	sign = "";
	if (**format == 'D')
	{
		arg->len = l;
		arg->has_uppercase = 1;
	}
	signed_length_processing(&num, arg_list, arg);
	if (num < 0 || arg->has_plus || arg->has_space)
	{
		if (num < 0)
		{
			num = -num;
			sign = "-";
		}
		else if (arg->has_plus)
			sign = "+";
		else if (arg->has_space)
			sign = " ";
		return (sign_force_processing(num, 10, arg, sign));
	}
	else
		return (uint_handler(num, 10, arg, sign));
}
