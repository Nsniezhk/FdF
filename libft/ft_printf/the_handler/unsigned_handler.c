/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:09:27 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/27 15:09:32 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "handler.h"
#include "extenctions.h"

size_t	unsigned_handler(char **format, va_list *args_list, t_arg *arg)
{
	uintmax_t num;

	if (**format == 'U')
		arg->len = l;
	unsigned_length_processing(&num, args_list, arg);
	return (uint_handler(num, 10, arg, NULL));
}
