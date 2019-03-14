/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:54:05 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/05/01 12:16:52 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"
#include "libft.h"
#include "extenctions.h"
#include <wchar.h>

size_t	wstr_precision_len(wchar_t *str, int precision, size_t len)
{
	if (*str == '\0' && precision == 0)
		return (len);
	else if (*str <= 0x7f && precision >= 1)
		return (wstr_precision_len(str + 1, precision - 1, len + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (wstr_precision_len(str + 2, precision - 2, len + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (wstr_precision_len(str + 3, precision - 3, len + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (wstr_precision_len(str + 4, precision - 4, len + 4));
	else
		return (len);
}

void	print_precision_wstr(wchar_t *str, size_t precision)
{
	size_t	len;

	len = 0;
	while (*str && len < precision)
	{
		if (*str <= 0x7F && len >= 1)
			len++;
		else if (*str <= 0x7FF)
			len += 2;
		else if (*str <= 0xFFFF)
			len += 3;
		else if (*str <= 0x10FFFF)
			len += 4;
		if (len <= precision)
			ft_putwchar(*str++);
	}
}

size_t	wstr_len(wchar_t *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			len += 1;
		else if (*str <= 0x7FF)
			len += 2;
		else if (*str <= 0xFFFF)
			len += 3;
		else if (*str <= 0x10FFFF)
			len += 4;
		str++;
	}
	return (len);
}

size_t	wstr_handler(char **format, va_list *args_list, t_arg *arg)
{
	size_t	len;
	size_t	i;
	wchar_t *str;

	i = 0;
	(void)format;
	str = va_arg(*args_list, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	len = arg->has_precision ?
	wstr_precision_len(str, arg->precision, 0) : wstr_len(str);
	if (arg->has_width && !arg->has_minus)
		print_space_or_zero(len, arg->width, arg->has_zero ? '0' : ' ');
	print_precision_wstr(str, len + 1);
	if (arg->has_width && arg->has_minus)
		print_space_or_zero(len, arg->width, ' ');
	return (arg->has_width ? FT_MAX(arg->width, len) : len);
}
