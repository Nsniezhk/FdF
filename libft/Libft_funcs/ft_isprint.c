/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:29:23 by nsniezhk          #+#    #+#             */
/*   Updated: 2017/11/17 13:57:40 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	int counter;

	counter = ' ';
	while (counter <= '~')
	{
		if (c == counter)
			return (1);
		counter++;
	}
	return (0);
}
