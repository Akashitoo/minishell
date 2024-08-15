/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:25:53 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/21 12:16:12 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnv;
	t_list	*res;

	res = NULL;
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst)
	{
		lstnv = (t_list *) malloc(sizeof(t_list));
		if (!lstnv)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		lstnv->content = f(lst->content);
		lstnv->next = NULL;
		ft_lstadd_back(&res, lstnv);
		lst = lst->next;
	}
	return (res);
}
