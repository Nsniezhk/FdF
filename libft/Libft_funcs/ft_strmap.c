/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:23:24 by nsniezhk          #+#    #+#             */
/*   Updated: 2017/11/27 17:24:03 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *res;
	char *p;

	if ((s && f) && (res = ft_strnew(ft_strlen(s))))
	{
		p = res;
		while (*s)
		{
			*res = f((char)*s);
			res++;
			s++;
		}
		return (p);
	}
	return (NULL);
}
