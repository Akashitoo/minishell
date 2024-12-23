/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:46:27 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/11 09:45:22 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*new_var(char *str, int is_mine)
{
	t_env	*var;

	var = malloc(sizeof(t_env));
	if (!var)
		return (NULL);
	var->str = str;
	var->is_mine = is_mine;
	var->next = NULL;
	return (var);
}

void	add_back_env(t_env *env, t_env *var)
{
	t_env	*current;

	current = env;
	while (current->next)
	{
		current = current->next;
	}
	current->next = var;
}

t_env	*create_env(char **tab)
{
	int		i;
	t_env	*env;

	if (!tab || !tab[0])
		return (NULL);
	env = new_var(tab[0], 0);
	i = 1;
	while (tab[i])
	{
		add_back_env(env, new_var(tab[i], 0));
		i++;
	}
	return (env);
}

void	free_environ(t_env *environ)
{
	t_env	*current;
	t_env	*next;

	if (!environ)
		return ;
	current = environ;
	next = current->next;
	while (current)
	{
		next = current->next;
		if (current->is_mine)
			free(current->str);
		free(current);
		current = next;
	}
	environ = NULL;
}
