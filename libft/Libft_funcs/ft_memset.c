/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:03:27 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 15:59:40 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *destination, int c, size_t lengh)
{
	while (lengh > 0)
	{
		lengh--;
		((unsigned char *)destination)[lengh] = (unsigned char)c;
	}
	return (destination);
}
