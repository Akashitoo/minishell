/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:05:53 by abalasub          #+#    #+#             */
/*   Updated: 2024/06/20 13:17:54 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

void	exec_line(t_token *token_list, t_env *environ)
{
	t_token	*current_token;
	t_cmd	*cmd_list;
	int infile;
	int outfile;

	infile = 0;
	outfile = 1;
	cmd_list = NULL;
	current_token = token_list;
	while (current_token)
	{
		if (current_token->type == 2)
		{
			infile = current_token->next->fd;
			current_token = current_token->next;
		}
		else if (current_token->type == 3)
		{
			outfile = current_token->next->fd;
			current_token = current_token->next;
		}
		else if (current_token->type == 1)
		{
			if (!cmd_list)
			{
				cmd_list = new_cmd(create_cmd_tab(current_token));
			}
			else
			{
				add_back_cmd_list(cmd_list, new_cmd(create_cmd_tab(current_token)));
			}
			while (current_token->next && current_token->next->type == 1)
			{
				current_token = current_token->next;
			}
		}
		current_token = current_token->next;
	}
	pipex(infile, outfile, cmd_list, environ);
	(void) environ;
	free_cmd_list(cmd_list);
}

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;
	t_env	*environ;
	t_token *tokens_list;

	environ = create_env(envp);
	while (1)
	{
		prompt = readline(">minishell$ ");
		tokens_list = parsing_extended(prompt);
		if (tokens_list)
		{
			if (ft_strncmp(tokens_list->str,"cd", 2) == 0)
				shell_cd(tokens_list);
			else if (ft_strncmp(tokens_list->str, "echo", 4) == 0)
				shell_echo(tokens_list);
			else if (ft_strncmp(tokens_list->str, "pwd", 3) == 0)
				shell_pwd();
			else if (ft_strncmp(tokens_list->str, "env", 3) == 0)
				shell_env(environ);
			else if (ft_strncmp(tokens_list->str, "export", 6) == 0)
				shell_export(environ, tokens_list);
			else if (ft_strncmp(tokens_list->str,"unset", 5) == 0)
				shell_unset(&environ, tokens_list);
			else if (ft_strncmp(tokens_list->str, "exit", 4) == 0)
				break;
			exec_line(tokens_list, environ);
			freetokens(tokens_list);
		}
	}
	free(prompt);
	freetokens(tokens_list);
	free_environ(environ);
	(void)argc;
	(void)argv;
}
