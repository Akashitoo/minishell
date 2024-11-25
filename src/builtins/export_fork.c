/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:46:36 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/10 18:11:33 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shell_export_fork_aux(int *i, char *str, int *return_value)
{
	ft_putstr_fd("export '", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid indentifier\n", 2);
	*return_value = 1;
	*i += 1;
}

void	shell_export_fork_aux2(char *str, int *return_value)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!is_char_name(str[i]))
		{
			shell_export_fork_aux(&i, str, return_value);
			continue ;
		}
		i++;
	}
}

void	shell_export_fork(char **tab, t_pipex *pipex)
{
	int		j;
	char	*str;
	int		return_value;

	j = 1;
	return_value = 0;
	while (tab[j])
	{
		str = tab[j];
		if (str[0] != '_' && (str[0] < 'a' || str[0] > 'z')
			&& (str[0] < 'A' || str[0] > 'Z'))
		{
			shell_export_fork_aux(&j, str, &return_value);
			continue ;
		}
		shell_export_fork_aux2(str, &return_value);
		j++;
	}
	close_all(return_value, pipex);
}
