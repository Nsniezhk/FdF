/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:21:43 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/27 15:21:44 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "handler.h"
#include "extenctions.h"

size_t	char_handler(char **format, va_list *args_list, t_arg *arg)
{
	if (arg->len == l)
		return (wchar_handler(format, args_list, arg));
	if (arg->has_width && !arg->has_minus)
		print_space_or_zero(1, arg->width, arg->has_zero ? '0' : ' ');
	ft_putchar(va_arg(*args_list, int));
	if (arg->has_width && arg->has_minus)
		print_space_or_zero(1, arg->width, ' ');
	return (arg->has_width ? FT_MAX(arg->width, 1) : 1);
}
