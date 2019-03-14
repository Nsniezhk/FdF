/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:50:02 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/02/24 16:19:19 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;

	if (lst && f)
	{
		if (!(res = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		res = f(lst);
		if (lst->next)
		{
			res->next = ft_lstmap(lst->next, f);
			if (res->next == NULL)
			{
				free(res);
				return (NULL);
			}
		}
		else
			res->next = NULL;
		return (res);
	}
	else
		return (NULL);
}
