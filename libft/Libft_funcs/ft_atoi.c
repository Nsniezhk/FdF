/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:51:56 by nsniezhk          #+#    #+#             */
/*   Updated: 2017/12/14 17:16:34 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *string)
{
	unsigned long		number;
	int					sign;

	number = 0;
	sign = 1;
	while (*string == ' ' || *string == '\t'
			|| *string == '\v' || *string == '\f'
			|| *string == '\r' || *string == '\n')
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign = -1;
		string++;
	}
	while (*string >= '0' && *string <= '9')
	{
		number = number * 10 + *string - '0';
		string++;
	}
	return ((int)number * sign);
}
