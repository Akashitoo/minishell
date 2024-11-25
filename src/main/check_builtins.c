/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:43:38 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/12 18:35:15 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_pipe_in_tokenlist(t_token *token_list)
{
	t_token	*temp;

	temp = token_list;
	while (temp)
	{
		if (temp->type == PIPE)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	print_error_fd_false(char *file)
{
	if (access(file, F_OK) == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if ((access(file, R_OK) == -1))
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if ((access(file, W_OK) == -1))
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
}

int	is_fd_ok(t_token *tokens_list, int flag, int *return_value)
{
	t_token	*current;
	t_token	*previous;

	if (flag)
		return (1);
	current = tokens_list;
	while (current)
	{
		if (current->fd == -1)
		{
			*return_value = 1;
			return (print_error_fd_false(current->str), 0);
		}
		previous = current;
		current = current->next;
	}
	return (1);
}

void	check_builtins_bis(t_env *environ, t_token **tokens_list,
	int *return_value, int flag)
{
	if (ft_strncmp((*tokens_list)->str, "exit", 5) == 0 && !flag)
	{
		shell_exit(*tokens_list, return_value, environ);
		if (*return_value != 1)
			return ;
	}
	else
		exec_line(*tokens_list, environ, return_value);
}

void	check_builtins(t_env **environ,
	t_token **tokens_list, int *return_value)
{
	int	flag;
	int	fd;

	fd = get_write_fd(*tokens_list);
	flag = is_pipe_in_tokenlist(*tokens_list);
	if (!is_fd_ok(*tokens_list, flag, return_value))
		return ;
	if (ft_strncmp((*tokens_list)->str, "cd", 3) == 0 && !flag)
		shell_cd(*tokens_list, return_value);
	else if (ft_strncmp((*tokens_list)->str, "echo", 5) == 0 && !flag)
		shell_echo(*tokens_list, return_value, fd);
	else if (ft_strncmp((*tokens_list)->str, "pwd", 4) == 0 && !flag)
		shell_pwd(return_value, fd);
	else if (ft_strncmp((*tokens_list)->str, "env", 4) == 0 && !flag)
		shell_env(*environ, return_value, fd, *tokens_list);
	else if (ft_strncmp((*tokens_list)->str, "export", 7) == 0 && !flag)
		*return_value = shell_export(environ, *tokens_list);
	else if (ft_strncmp((*tokens_list)->str, "unset", 6) == 0 && !flag)
		shell_unset(environ, *tokens_list, return_value);
	else
		check_builtins_bis(*environ, tokens_list, return_value, flag);
}
