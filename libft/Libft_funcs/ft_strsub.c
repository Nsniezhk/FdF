/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:46:24 by nsniezhk          #+#    #+#             */
/*   Updated: 2017/11/27 14:31:06 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *result;

	if (s && start < ft_strlen(s) && (result = ft_strnew(len)))
		return (ft_strncpy(result, s + start, len));
	else
		return (NULL);
}
