/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:51:06 by abalasub          #+#    #+#             */
/*   Updated: 2024/08/26 18:52:00 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lexing_akash/include/minishell.h"

t_cmd	*new_cmd(char **tab)
{
	t_cmd	*cmd;
	cmd = malloc(sizeof(t_cmd));
	if	(!cmd)
		return(NULL);
	cmd->cmd = tab;
	cmd->next = NULL;
	return (cmd);
}

void	add_back_cmd_list(t_cmd *cmd_list, t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd_list;
	while (current->next)
	{
		current = current->next; 
	}
	current->next = cmd;
}

char	**create_cmd_tab(t_token *first_word)
{
	t_token	*current;
	int	size;
	int	i;
	char	**tab;

	size = 0;
	current = first_word;
	while (current && current->type == 1)
	{
		size += 1;
		current = current->next;	
	}
	tab = malloc(sizeof(char *) * (size + 1) );
	if (!tab)
		return (NULL);
	current = first_word;
	i = 0; 
	while (current && current->type == 1)
	{
		tab[i] = current->str;
		current = current->next;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

void	free_cmd_list(t_cmd *cmd_list)
{
	t_cmd	*current;
	t_cmd	*next;

	current = cmd_list;

	while (current)
	{
		next = current->next;
		free(current->cmd);
		free(current);
		current = next;
	}
}