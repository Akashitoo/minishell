/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:33:41 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/11 09:08:02 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shell_unset2(t_token *current_token, t_env **current, t_env **env)
{
	t_env	*previous;

	previous = NULL;
	while (*current)
	{
		if ((ft_strncmp((*current)->str, current_token->str,
					ft_strlen(current_token->str)) == 0)
			&& ((*current)->str[ft_strlen(current_token->str)] == '='))
		{
			if (!previous)
				*env = (*current)->next;
			else
				previous->next = (*current)->next;
			if ((*current)->is_mine)
				free((*current)->str);
			free(*current);
			break ;
		}
		previous = *current;
		*current = (*current)->next;
	}
}

void	shell_unset(t_env **env, t_token *tokens_list, int *return_value)
{
	t_env	*current;
	t_token	*current_token;

	current = *env;
	current_token = tokens_list->next;
	while (current_token)
	{	
		shell_unset2(current_token, &current, env);
		current_token = current_token->next;
		current = *env;
	}	
	*return_value = 0;
}
