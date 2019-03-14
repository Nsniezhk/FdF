/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:09:06 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:04:45 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *string_1, const char *string_2)
{
	const char *temp_s1;
	const char *temp_s2;

	temp_s2 = string_2;
	if (!*string_2)
		return ((char*)string_1);
	while (*string_1)
	{
		if (*string_1 == *string_2)
		{
			temp_s1 = string_1;
			while (*temp_s1++ == *temp_s2++)
				if (*temp_s2 == '\0')
					return ((char*)string_1);
			temp_s2 = string_2;
		}
		string_1++;
	}
	return (NULL);
}
