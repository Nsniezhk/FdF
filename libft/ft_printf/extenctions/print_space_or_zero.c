/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space_or_zero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:19:15 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/20 16:51:56 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_space_or_zero(int str_len, int width, char space_or_zero)
{
	while (str_len++ < width)
		write(1, &space_or_zero, 1);
}
