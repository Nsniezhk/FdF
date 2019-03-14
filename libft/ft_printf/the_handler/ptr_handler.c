/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:54:47 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/05/01 19:50:41 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"
#include "extenctions.h"

size_t	ptr_handler(char **format, va_list *args_list, t_arg *arg)
{
	uintmax_t	ptr;

	(void)format;
	if (arg->has_precision)
		arg->has_zero = 0;
	arg->len = z;
	unsigned_length_processing(&ptr, args_list, arg);
	return (sign_force_processing(ptr, 16, arg, "0x"));
}
