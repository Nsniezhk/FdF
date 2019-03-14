/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:25:38 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:03:18 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncat(char *destination, char *src, size_t n)
{
	size_t counter;
	size_t size;

	counter = 0;
	size = 0;
	while (destination[size])
		size++;
	while (counter < n && src[counter])
	{
		destination[size] = src[counter];
		size++;
		counter++;
	}
	destination[size] = '\0';
	return (destination);
}
