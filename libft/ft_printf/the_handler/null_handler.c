/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:27:21 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/05/02 14:27:43 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "handler.h"
#include "extenctions.h"

size_t	null_handler(char **format, va_list *args_list, t_arg *arg)
{
	(void)args_list;
	if (arg->has_width && !arg->has_minus)
		print_space_or_zero(1, arg->width, arg->has_zero ? '0' : ' ');
	ft_putchar(**format);
	if (arg->has_width && arg->has_minus)
		print_space_or_zero(1, arg->width, ' ');
	return (arg->has_width ? FT_MAX(arg->width, 1) : 1);
}
