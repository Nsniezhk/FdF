/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:59:28 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:14:40 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *src)
{
	size_t		counter;
	size_t		lenght;
	char		*new_src;

	counter = 0;
	lenght = ft_strlen(src);
	new_src = (char*)malloc(lenght + 1);
	if (new_src == NULL)
		return (NULL);
	while (counter < lenght)
	{
		new_src[counter] = src[counter];
		counter++;
	}
	new_src[counter] = '\0';
	return (new_src);
}
