/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:43:08 by nsniezhk          #+#    #+#             */
/*   Updated: 2017/12/14 13:43:03 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	char	*found;
	int		counter;

	found = (char*)string;
	counter = ft_strlen(string);
	while (counter != -1)
	{
		if (found[counter] == (char)c)
			return (&found[counter]);
		counter--;
	}
	return (NULL);
}
