/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:29:34 by atrabut           #+#    #+#             */
/*   Updated: 2023/12/02 10:19:51 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	lineinlst(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (lst == NULL)
		return (0);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	while ((temp->content)[i])
	{
		if ((temp->content)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	firstline(t_list *lst)
{
	int		i;
	int		count;
	t_list	*temp;

	count = 0;
	temp = lst;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			count++;
			if (temp->content[i] == '\n')
				return (++count);
			i++;
		}
		temp = temp->next;
	}
	return (count + 1);
}

void	ft_lstadd_back(t_list **lst, t_list *new, int i)
{
	t_list	*temp;

	temp = *lst;
	(new->content)[i] = '\0';
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

t_list	*clearfirst(t_list *lst)
{
	t_list	*next;

	next = lst->next;
	free(lst->content);
	free(lst);
	return (next);
}

int	clearall(t_list *lst)
{
	while (lst)
		lst = clearfirst(lst);
	return (-1);
}
