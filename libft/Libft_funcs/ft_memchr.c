/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:18:50 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:01:29 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

const	void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*temp_src;
	size_t			counter;

	temp_src = (unsigned char*)src;
	counter = 0;
	while (counter < n)
	{
		if (temp_src[counter] == (unsigned char)c)
		{
			return (&src[counter]);
		}
		counter++;
	}
	return (NULL);
}
