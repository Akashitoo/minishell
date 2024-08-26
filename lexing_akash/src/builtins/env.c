/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:44:39 by abalasub          #+#    #+#             */
/*   Updated: 2024/08/26 21:44:50 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minishell.h"

void	shell_env(t_env *env)
{
	t_env	*current;

	current = env;

	while (current)
	{
		printf("%s\n", current->str);
		current = current->next;
	}
}
