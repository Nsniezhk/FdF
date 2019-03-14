/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extenctions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:38:01 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/05/07 14:38:29 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENCTIONS_H
# define EXTENCTIONS_H
# include "t_arg.h"
# include <stdint.h>
# include <stdio.h>

void			unsigned_length_processing(uintmax_t *num,
				va_list *list, t_arg *arg);
void			signed_length_processing(intmax_t *num,
				va_list *arg_list, t_arg *arg);
void			print_space_or_zero(int	str_len,
				int width, char space_or_zero);
unsigned int	num_precision_len(uintmax_t num,
				int base, char *sign, t_arg *arg);
unsigned int	numstr_len(uintmax_t num, int base);
size_t			sign_force_processing(uintmax_t num,
				int base, t_arg *arg, char *sign);
int				num_equal_zero(uintmax_t num, t_arg *arg);
void			print_num_base(uintmax_t nbr,
				int base, unsigned int num_len, t_arg *arg);

#endif
