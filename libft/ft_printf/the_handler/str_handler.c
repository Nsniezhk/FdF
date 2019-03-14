/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:00:31 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/22 16:39:29 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "handler.h"
#include "extenctions.h"

size_t	str_handler(char **format, va_list *list, t_arg *arg)
{
	char	*str;
	size_t	str_len;

	(void)format;
	if (arg->len == l)
		return (wstr_handler(format, list, arg));
	str = va_arg(*list, char*);
	if (str == NULL)
		str = "(null)";
	str_len = arg->has_precision ?
	ft_strnlen(str, arg->precision) : ft_strlen(str);
	if (arg->has_width && !arg->has_minus)
		print_space_or_zero(str_len, arg->width, arg->has_zero ? '0' : ' ');
	write(1, &(*str), str_len);
	if (arg->has_width && arg->has_minus)
		print_space_or_zero(str_len, arg->width, arg->has_zero ? '0' : ' ');
	return (arg->has_width ? FT_MAX(str_len, arg->width) : str_len);
}
