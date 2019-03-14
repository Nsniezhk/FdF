/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_precision_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:09:45 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/22 16:35:26 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "extenctions.h"

unsigned int	num_precision_len(uintmax_t num,
				int base, char *sign, t_arg *arg)
{
	unsigned int num_len;

	num_len = numstr_len(num, base);
	if (num == 0 && arg->has_precision && arg->precision == 0)
		num_len = 0;
	else if (arg->has_precision)
		num_len = FT_MAX(num_len, arg->precision);
	if (arg->has_hash && sign != NULL && num != 0)
		num_len += ft_strlen(sign);
	return (num_len);
}
