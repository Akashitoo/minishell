/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:51:27 by atrabut           #+#    #+#             */
/*   Updated: 2024/06/18 19:11:53 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	freetab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		ft_putstr_fd("freetab appeler avec un tableau null", 2);
	else
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

void	freetabn(char **tab, int n)
{
	int	i;

	i = 0;
	if (!tab)
		ft_putstr_fd("freetabn appeler avec un tableau null", 2);
	else 
	{
		while (i < n && tab[i] )
			free(tab[i++]);
		free(tab);
	}
}
void	freetokens(t_token *token_list)
{
	t_token	*temp;

	if (token_list != NULL)
	{
		while(token_list)
		{
			temp = token_list;
			free(token_list->str);
			token_list = token_list->next;
			free(temp);
		}
	}
}

