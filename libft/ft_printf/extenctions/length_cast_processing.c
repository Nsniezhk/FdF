/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_cast_processing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:59:11 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/22 16:42:48 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include "t_arg.h"
#include <stdarg.h>

void		unsigned_length_processing(uintmax_t *num,
			va_list *list, t_arg *arg)
{
	*num = va_arg(*list, uintmax_t);
	if (arg->len == hh)
		*num = (unsigned char)*num;
	else if (arg->len == h)
		*num = (unsigned short int)*num;
	else if (arg->len == l)
		*num = (unsigned long int)*num;
	else if (arg->len == ll)
		*num = (unsigned long long int)*num;
	else if (arg->len == j)
		*num = (uintmax_t)*num;
	else if (arg->len == z)
		*num = (size_t)*num;
	else
		*num = (unsigned int)*num;
}

void		signed_length_processing(intmax_t *num,
			va_list *arg_list, t_arg *arg)
{
	*num = va_arg(*arg_list, intmax_t);
	if (arg->len == hh)
		*num = (signed char)*num;
	else if (arg->len == h)
		*num = (short int)*num;
	else if (arg->len == l)
		*num = (long int)*num;
	else if (arg->len == ll)
		*num = (long long int)*num;
	else if (arg->len == j)
		*num = (intmax_t)*num;
	else if (arg->len == z)
		*num = (size_t)*num;
	else
		*num = (int)*num;
}
