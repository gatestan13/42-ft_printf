/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:51:44 by gatan             #+#    #+#             */
/*   Updated: 2021/05/06 04:05:13 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*elem;
	int		i;

	i = 0;
	res = NULL;
	while (lst)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (elem == NULL)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		if (i == 0)
			res = elem;
		else
			ft_lstadd_back(&res, elem);
		lst = lst->next;
		i++;
	}
	return (res);
}
