/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:12:12 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/12 19:00:47 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	is_builtins(char *cmd, char **cmd_options, t_pipex *pipex)
{
	if (ft_strncmp(cmd, "cd", 3) == 0)
		shell_cd_fork(cmd_options, pipex);
	else if (ft_strncmp(cmd, "echo", 5) == 0)
		shell_echo_fork(cmd_options, pipex);
	else if (ft_strncmp(cmd, "pwd", 4) == 0)
		shell_pwd_fork(pipex);
	else if (ft_strncmp(cmd, "env", 4) == 0)
		shell_env_fork(pipex, cmd_options);
	else if (ft_strncmp(cmd, "export", 7) == 0)
		shell_export_fork(cmd_options, pipex);
	else if (ft_strncmp(cmd, "unset", 6) == 0)
		close_all(0, pipex);
	else if (ft_strncmp(cmd, "exit", 5) == 0)
		shell_exit_fork(cmd_options, pipex);
	(void) pipex;
}

void	execute_cmd(t_pipex *pipex)
{	
	if (pipex->outfile == -1)
		error_file_exit(pipex, pipex->args->outfile_str);
	if (pipex->infile == -1)
		error_file_exit(pipex, pipex->args->infile_str);
	if (pipex->outfile != 1)
		dup2(pipex->outfile, 1);
	else
		dup2(pipex->current[1], 1);
	close(pipex->current[1]);
	if (pipex->infile != 0)
		dup2(pipex->infile, 0);
	else
		dup2(pipex->previous, 0);
	if (pipex->previous != 0)
		close(pipex->previous);
	close(pipex->current[0]);
	if (!pipex->args->cmd)
		close_all(0, pipex);
	close_all_fd(pipex->tokens_list);
	is_builtins(pipex->args->cmd[0], pipex->args->cmd, pipex);
	if (execve(get_path(pipex->args->cmd[0], pipex),
			pipex->args->cmd, pipex->envp) == -1)
		error_cmd_exit(pipex, pipex->args->cmd[0]);
}

void	execute_last(t_pipex *pipex)
{
	if (pipex->args2->infile_fd == 0)
		pipex->args2->infile_fd = pipex->previous;
	if (dup2(pipex->args2->outfile_fd, 1) == -1)
		error_file_exit(pipex, pipex->args2->outfile_str);
	if (dup2(pipex->args2->infile_fd, 0) == -1)
		error_file_exit(pipex, pipex->args2->infile_str);
	if (pipex->previous != 0)
		close(pipex->previous);
	if (!pipex->args2->cmd)
		close_all(0, pipex);
	close_all_fd(pipex->tokens_list);
	is_builtins(pipex->args2->cmd[0], pipex->args2->cmd, pipex);
	if (execve(get_path(pipex->args2->cmd[0], pipex),
			pipex->args2->cmd, pipex->envp) == -1)
	{
		error_cmd_exit(pipex, pipex->args2->cmd[0]);
	}
}

void	loop_pipe(t_pipex *pipex)
{
	pid_t	pid_inter;
	t_cmd	*current;

	current = pipex->cmd_list;
	while (current->next)
	{
		pipex->args = current;
		if (pipe(pipex->current) == -1)
			ft_putstr_fd("pipe failed", 2);
		pid_inter = fork();
		if (pid_inter == -1)
			ft_putstr_fd("process failed", 2);
		if (pid_inter == 0)
		{
			pipex->infile = current->infile_fd;
			pipex->outfile = current->outfile_fd;
			execute_cmd(pipex);
		}
		close(pipex->current[1]);
		if (pipex->previous != -1 && pipex->previous != 0)
			close(pipex->previous);
		pipex->previous = pipex->current[0];
		current = current->next;
	}
}

void	pipex(t_exec_line *structure, t_env *environ, int *return_value)
{
	pid_t	pid2;
	t_pipex	pipex;
	int		status;

	init_var(&pipex, structure, environ);
	if (!pipex.cmd_list)
	{
		no_command(&pipex, return_value);
		return ;
	}
	loop_pipe(&pipex);
	pid2 = fork();
	if (pid2 == -1)
		ft_putstr_fd("process failed", 2);
	if (pid2 == 0)
	{	
		pipex.outfile = pipex.args2->outfile_fd;
		pipex.infile = pipex.args2->infile_fd;
		execute_last(&pipex);
	}
	if (pipex.previous != 0)
		close(pipex.previous);
	*return_value = wait_all_process(structure->cmd_list, &status);
	free(pipex.envp);
}
