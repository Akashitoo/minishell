/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:36:53 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/12 19:04:53 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*last_cmd(t_cmd	*cmd_list)
{
	t_cmd	*current;

	if (!cmd_list)
		return (NULL);
	current = cmd_list;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}

char	**convert_to_tab(t_env *env)
{
	t_env	*current;
	int		size;
	int		i;
	char	**environ;

	current = env;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	environ = malloc (sizeof(char *) * (size + 1));
	current = env;
	i = 0;
	while (current)
	{
		environ[i] = current->str;
		current = current->next;
		i++;
	}
	environ[i] = 0;
	return (environ);
}

void	init_var(t_pipex *pipex, t_exec_line *structure, t_env *environ)
{
	pipex->previous = 0;
	pipex->args = NULL;
	pipex->cmd_list = structure->cmd_list;
	pipex->args2 = last_cmd(pipex->cmd_list);
	pipex->envp = convert_to_tab(environ);
	pipex->infile_str = structure->infile_str;
	pipex->outfile_str = structure->outfile_str;
	pipex->tokens_list = structure->tokens_list;
	pipex->environ = environ;
}

void	error_cmd_exit(t_pipex *pipex, char *file)
{
	if (access(file, F_OK) == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (access(file, X_OK) == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if (is_directory(file))
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Is a directory\n", 2);
	}
	free_close(pipex, 127);
}

void	error_file_exit(t_pipex *pipex, char *file)
{
	close(pipex->previous);
	close(pipex->current[0]);
	close(pipex->current[1]);
	if (access(file, F_OK) == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (access(file, R_OK) == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if (access(file, W_OK) == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	free_close(pipex, 1);
}
