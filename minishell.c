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

#include "lexing_akash/include/minishell.h"

/*
void	free_tab(char **tab)
{
	int 	i;

	i = 0;
	if (!tab)
		return ; 
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}*/
/*
t_token	*new_token(char *str, int type)
{

	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->str = str;
	token->type = type;
	token->next = NULL;
	return (token);	
}*/

void	add_token_back(t_token *tokens_list, t_token *added_token)
{
	t_token *current;

	current = tokens_list;
	while (current->next)
	{
		current = current->next;
	}
	current->next = added_token;
}

t_token	*create_tokens_list(char *prompt)
{
	t_data 	parsing;

	if (prompt == NULL)
		return (NULL);
	lexing_init(&parsing, prompt);
	if (!tokenizer(&parsing))
		return (NULL);
	return (parsing.token_list);
}

t_env	*new_var(char *str)
{
	t_env *var;

	var = malloc(sizeof(t_env));
	if (!var)
		return (NULL);
	var->str = str;
	var->next= NULL;
	return (var);
}

void	add_back_env(t_env *env, t_env *var)
{
	t_env *current;

	current = env;

	while (current->next)
	{
		current = current->next;
	}
	current->next = var;
}

t_env	*create_env(char **tab)
{
	int	i;
	t_env	*env;

	env = new_var(tab[0]);
	i = 1;
	while(tab[i])
	{
		add_back_env(env, new_var(tab[i]));
		i++;
	}
	return (env);

}

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

void	free_tokens_list(t_token *tokens_list)
{
	t_token	*current;
	t_token	*next;

	if (!tokens_list)
		return ;
	current = tokens_list;
	next = current->next;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
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
		free(current);
		current = next;
	}
	environ = NULL;
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
			infile = open(current_token->next->str, O_RDWR);
			current_token = current_token->next;
		}
		else if (current_token->type == 3)
		{
			outfile = current_token->next->fd;
			outfile = open(current_token->next->str, O_RDWR);
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
		tokens_list = create_tokens_list(prompt);
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
	free_tokens_list(tokens_list);
	free_environ(environ);
	(void)argc;
	(void)argv;
}
