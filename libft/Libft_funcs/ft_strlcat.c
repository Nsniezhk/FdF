/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:59:33 by nsniezhk          #+#    #+#             */
/*   Updated: 2017/11/27 14:28:17 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *src, size_t dest_size)
{
	char		*temp_dest;
	const char	*temp_src;
	size_t		counter;
	size_t		dest_len;

	counter = dest_size;
	temp_dest = destination;
	temp_src = src;
	while (counter-- != 0 && *temp_dest != '\0')
		temp_dest++;
	dest_len = temp_dest - destination;
	counter = dest_size - dest_len;
	if (counter == 0)
		return (dest_len + ft_strlen(temp_src));
	while (*temp_src != '\0')
	{
		if (counter != 1)
		{
			*temp_dest++ = *temp_src;
			counter--;
		}
		temp_src++;
	}
	*temp_dest = '\0';
	return (dest_len + (temp_src - src));
}
