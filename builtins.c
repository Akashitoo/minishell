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

#include "lexing_akash/include/minishell.h"

int	is_full_n(char *str)
{
	int i;

	i = 2;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	shell_echo(t_token *tokens_list)
{
	t_token *current;

	int	nl;

	nl = 1;
	current = tokens_list->next;

	while (current && (ft_strncmp(current->str, "-n", 2) == 0 && is_full_n(current->str)))
	{
		nl = 0;
		current = current->next;
	}
	while (current)
	{	
		printf("%s", current->str);
		if (current->next)
			printf(" ");
		current = current->next;
	}
	if (nl)
		printf("\n");
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
