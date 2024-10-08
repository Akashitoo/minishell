/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:36:53 by abalasub          #+#    #+#             */
/*   Updated: 2024/05/31 16:47:53 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minishell.h"

/*
void	init_var(t_data *pipex, char **argv, char **envp, int argc)
{
	pipex->envp = envp;
	pipex->argv = argv;
	pipex->args2 = ft_split(argv[argc - 2], ' ');
	pipex->args = NULL;
	pipex->infile = open(argv[1], O_RDWR);
	pipex->previous = pipex->infile;
	pipex->outfile = open(argv[argc - 1], O_RDWR | O_TRUNC);
	if (pipex->outfile == -1)
	{
		pipex->outfile = open(argv[argc - 1], O_WRONLY
				| O_CREAT | O_EXCL, 0644);
	}
}
*/

char	**last_cmd(t_cmd	*cmd_list)
{
	t_cmd	*current;

	current = cmd_list;
	while (current->next)
	{
		current = current->next;
	}
	return (current->cmd);
}

char	**convert_to_tab(t_env *env)
{
	t_env	*current;
	int	size;
	int	i;
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

void	init_var(t_pipex *pipex, int infile, int outfile, t_cmd *cmd_list, t_env *environ)
{
	pipex->infile = infile;
	pipex->outfile = outfile;
	pipex->previous = infile;
	pipex->args = NULL;
	pipex->cmd_list = cmd_list;
	pipex->args2 = last_cmd(cmd_list);
	pipex->envp = convert_to_tab(environ);
}

void	error_cmd_exit(t_pipex *pipex, char *file, int status)
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
	free_close(pipex);
	exit(status);
}

void	error_file_exit(t_pipex *pipex, char *file, int status)
{
	if (access(file, F_OK) == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (!status && access(file, R_OK) == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if (status && access(file, W_OK) == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	free_close(pipex);
	exit(status);
}
