/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:44:13 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/08 19:53:33 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shell_pwd(int *return_value, int write_fd)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
	{	
		ft_putstr_fd("pwd failed !", 2);
		*return_value = 1;
		return ;
	}
	ft_putstr_fd(path, write_fd);
	ft_putstr_fd("\n", write_fd);
	free(path);
	*return_value = 0;
}

void	shell_pwd_fork(t_pipex *pipex)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
	{	
		ft_putstr_fd("pwd failed !", 2);
		close_all(1, pipex);
	}
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
	close_all(0, pipex);
}
