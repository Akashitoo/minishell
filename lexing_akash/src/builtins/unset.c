/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:47:23 by abalasub          #+#    #+#             */
/*   Updated: 2024/06/14 15:22:49 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shell_unset(t_env **env, t_token *tokens_list)
{
	t_env	*previous;
	t_env *current;
	t_token *current_token;

	current = *env;
	current_token = tokens_list->next;
	previous = NULL;
	while (current_token)
	{
		while (current)
		{
			if ((ft_strncmp(current->str,current_token->str, ft_strlen(current_token->str)) == 0)
				&& (current->str[ft_strlen(current_token->str)] == '='))
			{
				if (!previous)
					*env = current->next;
				else
					previous->next = current->next;	
			}
			previous= current;
			current = current->next;
		}
		current_token= current_token->next;
		current = *env;
		previous = NULL;
	}	
}
