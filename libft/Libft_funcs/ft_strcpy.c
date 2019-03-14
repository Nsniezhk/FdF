/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:38:12 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/05 15:22:07 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destination, const char *src)
{
	size_t len;

	len = 0;
	while (src[len])
	{
		destination[len] = src[len];
		len++;
	}
	destination[len] = '\0';
	return (destination);
}
