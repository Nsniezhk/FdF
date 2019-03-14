/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arg.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:39:23 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/05/07 14:39:39 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ARG_H
# define T_ARG_H

typedef	enum	e_length
{	no_len,
	hh, h,
	l, ll,
	j, z
}				t_len;
typedef struct	s_arg
{
	int				has_minus : 1;
	int				has_plus : 1;
	int				has_space : 1;
	int				has_hash : 1;
	int				has_precision : 1;
	int				has_width : 1;
	int				has_zero : 1;
	int				has_uppercase : 1;
	unsigned int	width;
	unsigned int	precision;
	t_len			len;
}				t_arg;

#endif
