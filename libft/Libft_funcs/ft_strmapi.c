/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:51:06 by nsniezhk          #+#    #+#             */
/*   Updated: 2017/11/27 14:29:27 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	char			*p;
	unsigned int	count;

	count = 0;
	if ((s && f) && (result = ft_strnew(ft_strlen(s))))
	{
		p = result;
		while (*s)
		{
			*result = f(count++, (char)*s);
			result++;
			s++;
		}
		return (p);
	}
	return (NULL);
}
