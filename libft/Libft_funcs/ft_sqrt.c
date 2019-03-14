/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:37:11 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/01/24 13:56:22 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int num)
{
	int	sq_root;

	sq_root = num;
	while ((sq_root * sq_root) != num)
		sq_root--;
	return (sq_root);
}
