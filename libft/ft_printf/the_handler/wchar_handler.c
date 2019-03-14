/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:54:27 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/27 15:54:30 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "extenctions.h"
#include <wchar.h>

size_t	wchar_handler(char **format, va_list *args_list, t_arg *arg)
{
	unsigned	len;
	wchar_t		chr;

	(void)format;
	chr = (wchar_t)va_arg(*args_list, wint_t);
	if (chr <= 0x7F)
		len = 1;
	else if (chr <= 0x7FF)
		len = 2;
	else if (chr <= 0xFFFF)
		len = 3;
	else if (chr <= 0x10FFFF)
		len = 4;
	if (arg->has_width && !arg->has_minus)
		print_space_or_zero(1, arg->width, arg->has_zero ? '0' : ' ');
	ft_putwchar(chr);
	if (arg->has_width && arg->has_minus)
		print_space_or_zero(1, arg->width, ' ');
	return (arg->has_width ? FT_MAX(arg->width, len) : len);
}
