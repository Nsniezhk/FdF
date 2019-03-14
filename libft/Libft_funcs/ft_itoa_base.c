/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:35:13 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/21 19:14:07 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign_str_define(int *num, int *base,
		unsigned int *nbr, char **num_str)
{
	int	sign;

	sign = 0;
	if (*num < 0 && *base == 10)
	{
		sign = 1;
		*nbr = -(*num);
		*num_str = ft_strnew(ft_numlen(*nbr) + 1);
	}
	else if (*num_str == NULL)
	{
		*nbr = *num;
		*num_str = ft_strnew(ft_numlen(*nbr));
	}
	return (sign);
}

char		*ft_itoa_base(int num, int base)
{
	unsigned int	nbr;
	unsigned int	i;
	int				neg;
	int				digit;
	char			*num_str;

	neg = 0;
	i = 0;
	digit = 0;
	num_str = NULL;
	if (num == 0)
		return (ft_strdup("0"));
	neg = sign_str_define(&num, &base, &nbr, &num_str);
	while (nbr != 0)
	{
		digit = nbr % base;
		num_str[i++] = (digit > 9) ? (digit - 10) + 'a' : digit + '0';
		nbr = nbr / base;
	}
	if (neg)
		num_str[i++] = '-';
	ft_strrev(num_str);
	return (num_str);
}
