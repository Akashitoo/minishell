/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:46:41 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/11 17:50:22 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

void	free_close(t_pipex *pipex, int return_value)
{
	if (pipex->previous != 0 && pipex->previous != pipex->infile)
		close(pipex->previous);
	close_all(return_value, pipex);
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

int	is_directory(const char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) != 0)
	{
		perror("stat");
		return (0);
	}
	return (S_ISDIR(path_stat.st_mode));
}

char	*get_path(char *cmd, t_pipex *pipex)
{
	int		j;
	char	*path;
	char	*final_path;
	char	**paths;

	if (access(cmd, F_OK | X_OK) == 0 && !is_directory(cmd))
		return (cmd);
	paths = env_path(pipex->envp);
	j = 0;
	while (paths && paths[j])
	{
		path = ft_strjoin(paths[j], "/");
		final_path = ft_strjoin(path, cmd);
		if (access(final_path, F_OK | X_OK) == 0 && !is_directory(final_path))
			return (final_path);
		free(path);
		free(final_path);
		j++;
	}
	free_tab(paths);
	return (error_cmd_exit(pipex, cmd), NULL);
}
