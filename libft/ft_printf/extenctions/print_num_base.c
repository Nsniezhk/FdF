/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:58:22 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/05/01 19:58:48 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "extenctions.h"

int			num_equal_zero(uintmax_t num, t_arg *arg)
{
	if (num == 0)
	{
		if (arg->has_precision && arg->precision == 0)
			return (1);
		ft_putchar('0');
		return (1);
	}
	return (0);
}

void		print_num_base(uintmax_t nbr, int base,
			unsigned int num_len, t_arg *arg)
{
	unsigned int	i;
	int				digit;
	char			letter;
	char			*num_str;

	i = 0;
	digit = 0;
	letter = arg->has_uppercase ? 'A' : 'a';
	if (arg->has_precision)
		print_space_or_zero(num_len, arg->precision, '0');
	if (num_equal_zero(nbr, arg))
		return ;
	num_str = ft_strnew(num_len);
	while (nbr != 0)
	{
		digit = nbr % base;
		num_str[i++] = (digit > 9) ? (digit - 10) + letter : digit + '0';
		nbr = nbr / base;
	}
	ft_strrev(num_str);
	ft_putstr(num_str);
	ft_strdel(&num_str);
}
