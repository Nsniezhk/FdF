/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numstr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:56:43 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/22 17:15:04 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

unsigned int	numstr_len(uintmax_t num, int base)
{
	unsigned int	num_len;

	num_len = 1;
	if (num == 0)
		return (num_len);
	while ((num /= base))
		num_len++;
	return (num_len);
}
