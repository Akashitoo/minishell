/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:45:12 by abalasub          #+#    #+#             */
/*   Updated: 2024/08/26 21:45:24 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minishell.h"

int	is_equal_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

void	shell_export(t_env *env, t_token *tokens_list)
{
	char	*str;
	t_env	*current;

	str = tokens_list->next->str;
	current = env;
	if (is_equal_sign(str))
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_var(str);
	}
}
