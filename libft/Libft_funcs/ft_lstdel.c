/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:05:58 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:18:57 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *next_temp;

	if (alst && *alst && del)
	{
		temp = (*alst);
		while (temp)
		{
			next_temp = temp->next;
			del(temp->content, temp->content_size);
			free(temp);
			temp = next_temp;
		}
		*alst = NULL;
	}
}
