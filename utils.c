/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:46:41 by abalasub          #+#    #+#             */
/*   Updated: 2024/05/31 18:04:25 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_close(t_data *pipex)
{
	free_tab(pipex->args2);
	free_tab(pipex->args);
}

char	**env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

char	*get_path(char *cmd, t_data *pipex, int last_cmd)
{
	int		j;
	char	*path;
	char	*final_path;
	char	**paths;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	paths = env_path(pipex->envp);
	j = 0;
	while (paths && paths[j])
	{
		path = ft_strjoin(paths[j], "/");
		final_path = ft_strjoin(path, cmd);
		if (access(final_path, F_OK | X_OK) == 0)
			return (final_path);
		free(path);
		free(final_path);
		j++;
	}
	free_tab(paths);
	return (error_cmd_exit(pipex, cmd, last_cmd), NULL);
}

char	*get_path2(char *cmd, t_data *pipex, int last_cmd)
{
	int		j;
	char	*path;
	char	*final_path;
	char	**paths;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	paths = env_path(pipex->envp);
	j = 0;
	while (paths && paths[j])
	{
		path = ft_strjoin(paths[j], "/");
		final_path = ft_strjoin(path, cmd);
		if (access(final_path, F_OK | X_OK) == 0)
		{
			return (final_path);
		}
		free(path);
		free(final_path);
		j++;
	}
	return (error_cmd_exit(pipex, cmd, last_cmd), NULL);
}
