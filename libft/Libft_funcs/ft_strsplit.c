/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:45:03 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:16:00 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*ft_word(char const *s, char c)
{
	size_t		length;
	char const	*word_detect;
	char		*word;

	length = 0;
	word_detect = (char *)s;
	while (*word_detect && *word_detect != c)
	{
		length++;
		word_detect++;
	}
	if ((word = ft_strnew(length)))
		ft_strncpy(word, s, length);
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**split;
	size_t		row;

	row = 0;
	if (!s ||
			!(split = (char**)malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	if (ft_wordcount(s, c) != 0)
	{
		while (*s)
		{
			if (*s && *s != c)
			{
				split[row++] = ft_word(s, c);
				while (*s && *s != c)
					s++;
			}
			while (*s && *s == c)
				s++;
		}
	}
	split[row] = NULL;
	return (split);
}
