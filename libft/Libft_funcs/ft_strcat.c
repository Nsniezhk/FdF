/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:52:50 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/05 15:22:38 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *add)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (destination[i])
		i++;
	while (add[j])
		destination[i++] = add[j++];
	destination[i] = '\0';
	return (destination);
}
