/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:44:43 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:01:04 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *destination, const void *src, size_t n)
{
	unsigned char		*temp_destination;
	const unsigned char	*temp_src;

	temp_destination = destination;
	temp_src = src;
	if (temp_destination > temp_src)
		while (n--)
			temp_destination[n] = temp_src[n];
	else
		while (n--)
			*temp_destination++ = *temp_src++;
	return (destination);
}
