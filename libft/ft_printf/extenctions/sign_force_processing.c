/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_force_processing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:58:35 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/22 19:14:54 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extenctions.h"
#include "handler.h"
#include "libft.h"

size_t	sign_force_processing(uintmax_t num, int base, t_arg *arg, char *sign)
{
	unsigned	num_len;
	size_t		num_chop;

	num_chop = ft_strlen(sign);
	num_len = num_precision_len(num, base, sign, arg) + num_chop;
	if (arg->has_width && !arg->has_minus && !arg->has_zero)
	{
		print_space_or_zero(num_len, arg->width, ' ');
		if (num_len <= arg->width)
			num_chop += FT_MAX(arg->width - num_len, 0);
		arg->has_width = 0;
	}
	else if (arg->has_width)
		arg->width -= ft_strlen(sign);
	ft_putstr(sign);
	return (uint_handler(num, base, arg, sign) + num_chop);
}
