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

#include "minishell.h"

void	shell_echo(t_token *tokens_list)
{
	t_token *current;

	current = tokens_list->next;

	if (ft_strncmp(current->str, "-n", 2) == 0)
	{
		current = current->next;
		while (current)
		{	
			printf("%s", current->str);
			if (current->next)
				printf(" ");
			current = current->next;
		}
	}
	else
	{
		while (current)
		{
			printf("%s", current->str);
			if (current->next)
				printf(" ");
			current = current->next;
		}
		printf("\n");
	}
}

void	shell_cd(t_token *tokens_list)
{
	t_token	*current;

	current = tokens_list->next;

	if (!current)
		chdir("/home/abalasub");	
	else if (access(current->str, F_OK | X_OK) == 0)
		chdir(current->str);
	else if (access(current->str, F_OK))
		printf("cd: no such file or directory: %s\n", current->str);
	else if (access(current->str, X_OK))
		printf("cd : permission denied: %s\n", current->str);
}

void	shell_pwd(void)
{
	char	path[4096];

	getcwd(path, 4096);
	printf("%s\n",path);
}

void	shell_env(t_env *env)
{
	t_env	*current;

	current = env;

	while (current)
	{
		printf("%s\n", current->str);
		current = current->next;
	}
}

void	shell_export(t_env *env, t_token *tokens_list)
{
	char	*str;
	t_env	*current;

	str = tokens_list->next->str;
	current = env;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new_var(str);
}

void	shell_unset(t_env *env, t_token *tokens_list)
{
	t_env	*previous;
	t_env *current;

	current = env;
	previous = NULL;

	while (current)
	{
		if (ft_strncmp(current->str,tokens_list->next->str, ft_strlen(tokens_list->next->str)) == 0)
		{
			if (!previous)
				env = current->next;
			else
			{
				previous->next = current->next;
				env = previous;
			}
				
		}
		previous= current;
		current = current->next;
	}
}
