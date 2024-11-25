/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:51:01 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/12 18:42:30 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shell_export_num2(t_export *structure,
	t_env **last, t_env **current, t_env **env)
{
	if (is_equal_sign(structure->src))
	{
		*current = *env;
		structure->dest = malloc(sizeof(char)
				* (ft_strlen(structure->src) + 1));
		while (*current)
		{
			if (!((*current)->next))
				*last = *current;
			if (ft_strncmp((*current)->str, structure->src,
					is_equal_sign(structure->src) + 1) == 0)
			{	
				shell_export_aux(structure->dest, structure->src, current);
				return ;
			}
			*current = (*current)->next;
		}
		ft_memcpy(structure->dest, structure->src,
			(size_t)ft_strlen(structure->src) + 1);
		if (!*structure->env)
			*env = new_var(structure->dest, 1);
		else
			(*last)->next = new_var(structure->dest, 1);
	}
}

int	check_var(t_token	**current_token, t_export *structure)
{
	if (!is_variable_valid(structure->src))
	{
		*current_token = (*current_token)->next;
		structure->is_error = 1;
		return (1);
	}
	return (0);
}

int	shell_export(t_env **env, t_token *tokens_list)
{
	t_token		*current_token;
	t_export	structure;
	t_env		*current;
	t_env		*last;

	if (!tokens_list->next)
		return (0);
	structure.env = env;
	structure.is_error = 0;
	current_token = tokens_list->next;
	while (current_token)
	{
		if (current_token->type != 1)
		{
			if (current_token->next)
				current_token = current_token->next->next;
			continue ;
		}
		structure.src = current_token->str;
		if (check_var(&current_token, &structure))
			continue ;
		shell_export_num2(&structure, &last, &current, env);
		current_token = current_token->next;
	}
	return (structure.is_error);
}
