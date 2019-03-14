/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:58:43 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/01 15:28:01 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *src, size_t lenght)
{
	size_t		counter;
	char		*result;

	counter = 0;
	result = (char*)malloc(lenght + 1);
	if (result == NULL)
		return (NULL);
	while (counter < lenght)
	{
		result[counter] = src[counter];
		counter++;
	}
	result[counter] = '\0';
	return (result);
}
