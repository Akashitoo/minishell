/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:12:12 by abalasub          #+#    #+#             */
/*   Updated: 2024/08/08 16:54:04 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lexing_akash/include/minishell.h"

void	execute_cmd(t_pipex *pipex)
{
	close(pipex->current[0]);
	dup2(pipex->current[1], 1);
	close(pipex->current[1]);
	dup2(pipex->previous, 0);
	close(pipex->previous);
	if (execve(get_path(pipex->args[0], pipex, 0),
			pipex->args, pipex->envp) == -1)
		error_cmd_exit(pipex, pipex->args[0], 0); 
}

void	execute_last(t_pipex *pipex)
{
	dup2(pipex->previous, 0);
	close(pipex->previous);
	dup2(pipex->outfile, 1);
	if (execve(get_path(pipex->args2[0], pipex, 127),
			pipex->args2, pipex->envp) == -1)
		error_cmd_exit(pipex, pipex->args[0], 0);
}

void	loop_pipe(t_pipex *pipex)
{
	pid_t	pid_inter;
	t_cmd	*current;

	current = pipex->cmd_list;
	while (current->next)
	{
		pipex->args = current->cmd;
		if (pipe(pipex->current) == -1)
		ft_putstr_fd("pipe failed", 2);
		pid_inter = fork();
		if (pid_inter == -1)
		ft_putstr_fd("process failed", 2);
		if (pid_inter == 0)
			execute_cmd(pipex);
		close(pipex->current[1]);
		pipex->previous = pipex->current[0];
		current = current->next;
	}
}


void	pipex(int infile, int outfile, t_cmd *cmd_list, t_env *environ)
{
	pid_t pid2;
	t_pipex	pipex;
	int	status;

	init_var(&pipex, infile, outfile, cmd_list, environ);
	loop_pipe(&pipex);
	pid2 = fork();
	if (pid2 == -1)
		ft_putstr_fd("process failed", 2);
	if (pid2 == 0)
		execute_last(&pipex);
	close(pipex.previous);
	waitpid(-1, &status, 0);
	free(pipex.envp);
}