/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:39:25 by abalasub          #+#    #+#             */
/*   Updated: 2024/08/26 21:39:34 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minishell.h"

void	shell_cd(t_token *tokens_list)
{
	t_token	*current;

	current = tokens_list->next;

	if (!current)
		chdir("/home/abalasub");	
	else if (access(current->str, F_OK | X_OK) == 0)
		chdir(current->str);
	else if (access(current->str, F_OK))
		printf("cd: no such file or directory: %s\n", current->str);
	else if (access(current->str, X_OK))
		printf("cd : permission denied: %s\n", current->str);
}
