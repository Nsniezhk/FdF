/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:07:59 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:05:15 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *string_1, const char *string_2, size_t length)
{
	const char	*temp_s1;
	const char	*temp_s2;
	size_t		count;

	temp_s2 = string_2;
	if (!*string_2)
		return ((char*)string_1);
	while (length-- && *string_1)
	{
		if (*string_1 == *string_2)
		{
			temp_s1 = string_1;
			count = length;
			while (*temp_s1++ == *temp_s2++)
			{
				if (*temp_s2 == '\0')
					return ((char*)string_1);
				if (count-- == 0)
					break ;
			}
			temp_s2 = string_2;
		}
		string_1++;
	}
	return (NULL);
}
