/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:36:29 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/03/19 14:32:08 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count_1;
	size_t	count_2;
	size_t	l_1;
	size_t	l_2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	l_1 = ft_strlen(s1);
	l_2 = ft_strlen(s2);
	if (!(result = ft_strnew(l_1 + l_2)))
		return (NULL);
	count_1 = -1;
	count_2 = -1;
	while (++count_1 < l_1)
		*(result + count_1) = *(s1 + count_1);
	while (++count_2 < l_2)
		*(result + count_1++) = *(s2 + count_2);
	return (result);
}
