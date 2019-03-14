/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:12:45 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:02:58 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *destination, const char *src, size_t length)
{
	size_t counter;

	counter = 0;
	while (src[counter] != '\0' && counter < length)
	{
		destination[counter] = src[counter];
		counter++;
	}
	while (counter < length)
	{
		destination[counter] = '\0';
		counter++;
	}
	return (destination);
}
