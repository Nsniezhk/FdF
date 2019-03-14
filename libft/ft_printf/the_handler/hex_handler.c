/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:49:17 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/05/01 19:49:40 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"
#include "libft.h"
#include "extenctions.h"

size_t	hex_handler(char **format, va_list *args_list, t_arg *arg)
{
	uintmax_t	num;
	char		*sign;

	sign = "0x";
	unsigned_length_processing(&num, args_list, arg);
	if (**format == 'X')
	{
		arg->has_uppercase = 1;
		sign = "0X";
	}
	if (arg->has_hash && arg->has_width && arg->has_zero)
		arg->width -= ft_strlen(sign);
	return (uint_handler(num, 16, arg, sign));
}
