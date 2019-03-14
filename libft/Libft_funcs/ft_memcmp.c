/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:47:41 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:01:50 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	counter = 0;
	temp_s1 = (unsigned char*)s1;
	temp_s2 = (unsigned char*)s2;
	while (counter < n)
	{
		if (temp_s1[counter] != temp_s2[counter])
			return (temp_s1[counter] - temp_s2[counter]);
		counter++;
	}
	return (0);
}
