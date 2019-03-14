/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:51:17 by nsniezhk          #+#    #+#             */
/*   Updated: 2017/12/14 13:50:09 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int convert;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		convert = -n;
	}
	else
		convert = n;
	if (convert >= 10)
	{
		ft_putnbr_fd(convert / 10, fd);
		ft_putnbr_fd(convert % 10, fd);
	}
	else
		ft_putchar_fd(convert + '0', fd);
}
