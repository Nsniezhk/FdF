/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:09:04 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/05 14:51:22 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	in;
	size_t	out;

	in = 0;
	if (s == NULL)
		return (NULL);
	out = ft_strlen(s) - 1;
	while (s[in] != '\0' && (s[in] == ' ' ||
				s[in] == '\n' || s[in] == '\t'))
		in++;
	if (s[in] == '\0')
		return (ft_strnew(1));
	while (s[out] == ' ' || s[out] == '\n' || s[out] == '\t')
		out--;
	return (ft_strsub(s, in, (out - in) + 1));
}
