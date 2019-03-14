/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:59:59 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/04/22 15:00:18 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"
#include "libft.h"

void		get_specifier(t_handler *spec)
{
	spec['%'] = &percent_handler;
	spec['s'] = &str_handler;
	spec['S'] = &wstr_handler;
	spec['p'] = &ptr_handler;
	spec['d'] = &int_handler;
	spec['D'] = &int_handler;
	spec['i'] = &int_handler;
	spec['o'] = &octal_handler;
	spec['O'] = &octal_handler;
	spec['u'] = &unsigned_handler;
	spec['U'] = &unsigned_handler;
	spec['x'] = &hex_handler;
	spec['X'] = &hex_handler;
	spec['c'] = &char_handler;
	spec['C'] = &wchar_handler;
}

t_handler	define_handler(char c)
{
	static t_handler	*spec = NULL;

	if (spec == NULL)
		spec = ft_memalloc(sizeof(*spec) * 256);
	if (spec != NULL)
		get_specifier(spec);
	return (spec[(int)c]);
}
