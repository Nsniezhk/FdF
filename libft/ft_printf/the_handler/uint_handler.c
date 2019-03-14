/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:46:21 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/22 19:20:28 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extenctions.h"
#include "libft.h"
#include "t_arg.h"

size_t		uint_handler(uintmax_t num, int base, t_arg *arg, char *sign)
{
	unsigned int	num_len;
	unsigned int	strnum_len;

	if (arg->has_precision)
		arg->has_zero = 0;
	num_len = numstr_len(num, base);
	if (arg->has_width && !arg->has_minus && arg->has_zero)
	{
		arg->precision = FT_MAX(arg->width, num_len);
		arg->has_precision = 1;
		arg->has_width = 0;
	}
	strnum_len = num_precision_len(num, base, sign, arg);
	if (arg->has_width && !arg->has_minus)
		print_space_or_zero(strnum_len, arg->width, arg->has_zero ? '0' : ' ');
	if (arg->has_hash && sign != NULL && num != 0)
		ft_putstr(sign);
	print_num_base(num, base, num_len, arg);
	if (arg->has_width && arg->has_minus)
		print_space_or_zero(strnum_len, arg->width, ' ');
	return (arg->has_width ? FT_MAX(strnum_len, arg->width) : strnum_len);
}
