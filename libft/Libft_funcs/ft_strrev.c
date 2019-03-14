/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:03:57 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/21 16:32:26 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	char	*str_end;
	char	str_start;

	str_end = str + (ft_strlen(str) - 1);
	while (str < str_end)
	{
		str_start = *str;
		*str++ = *str_end;
		*str_end-- = str_start;
	}
}
