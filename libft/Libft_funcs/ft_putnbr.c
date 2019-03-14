/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:36:29 by nsniezhk          #+#    #+#             */
/*   Updated: 2017/12/14 13:47:33 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int convert;

	if (n < 0)
	{
		ft_putchar('-');
		convert = -n;
	}
	else
		convert = n;
	if (convert >= 10)
	{
		ft_putnbr(convert / 10);
		ft_putnbr(convert % 10);
	}
	else
		ft_putchar(convert + '0');
}
