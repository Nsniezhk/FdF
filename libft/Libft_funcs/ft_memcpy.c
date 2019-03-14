/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:22:45 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:00:13 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *destination, const void *src, size_t n)
{
	size_t				counter;
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	counter = 0;
	temp_dest = destination;
	temp_src = src;
	while (counter < n)
	{
		temp_dest[counter] = temp_src[counter];
		counter++;
	}
	destination = temp_dest;
	return (destination);
}
