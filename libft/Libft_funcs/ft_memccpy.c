/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:11:31 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:00:46 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *destination, const void *src, int c, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			counter;

	temp_dest = (unsigned char*)destination;
	temp_src = (unsigned char*)src;
	counter = 0;
	while (counter < n)
	{
		temp_dest[counter] = temp_src[counter];
		if (temp_src[counter] == (unsigned char)c)
			return (&destination[counter + 1]);
		counter++;
	}
	return (NULL);
}
