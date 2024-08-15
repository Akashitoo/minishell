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
#include "pipex.h"

void	execute_cmd(t_data *pipex, int i)
{
	close(pipex->current[0]);
	dup2(pipex->current[1], 1);
	close(pipex->current[1]);
	if (dup2(pipex->previous, 0))
		error_file_exit(pipex, pipex->argv[1], 1);
	close(pipex->previous);
	if (execve(get_path(pipex->args[0], pipex, 0),
			pipex->args, pipex->envp) == -1)
		error_cmd_exit(pipex, pipex->argv[i], 0);
}

void	execute_last(t_data *pipex, int argc)
{
	dup2(pipex->previous, 0);
	close(pipex->previous);
	if (dup2(pipex->outfile, 1) < 0)
		error_file_exit(pipex, pipex->argv[argc - 1], 1);
	if (execve(get_path(pipex->args2[0], pipex, 127),
			pipex->args2, pipex->envp) == -1)
		error_cmd_exit(pipex, pipex->argv[argc - 2], 0);
}

void	loop_pipe(t_data *pipex, int argc)
{
	pid_t	pid_inter;
	int	i;

	i = 2;
	while (i < argc - 2)
	{
		pipex->args = ft_split(pipex->argv[i], ' ');
		if (pipe(pipex->current) == -1)
			ft_putstr_fd("pipe failed", 2);
		pid_inter = fork();
		if (pid_inter == -1)
			ft_putstr_fd("process failed", 2);
		if (pid_inter == 0)
			execute_cmd(pipex, i);
		close(pipex->current[1]);
		pipex->previous = pipex->current[0];
		free_tab(pipex->args);
		i++;
	}
}
/*
int	main(int argc, char **argv, char **envp)
{
	pid_t	pid2;
	t_data	pipex;
	int		status;
	
	if (argc < 5)
		return (ft_putstr_fd("Bad argument(s)\n", 2), 1);
	init_var(&pipex, argv, envp, argc);
	loop_pipe(&pipex, argc);
	pid2 = fork();
	if (pid2 == -1)
		ft_putstr_fd("process failed", 2);
	if (pid2 == 0)
		execute_last(&pipex, argc);
	close(pipex.previous);
	waitpid(-1, &status, 0);
	free_tab(pipex.args2);
	exit(0);
}
*/

void	pipex(int infile, int outfile, t_cmd cmd_list, t_env environ)
{
	pid_t pid2;
	t_data	pipex;
	int	status;

	init_var(&pipex, infile, outfile, cmd_list, environ);
}