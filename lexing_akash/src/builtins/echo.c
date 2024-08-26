/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:38:57 by abalasub          #+#    #+#             */
/*   Updated: 2024/08/26 21:38:59 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minishell.h"

int	is_full_n(char *str)
{
	int i;

	i = 2;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	shell_echo(t_token *tokens_list)
{
	t_token *current;

	int	nl;

	nl = 1;
	current = tokens_list->next;

	while (current && (ft_strncmp(current->str, "-n", 2) == 0 && is_full_n(current->str)))
	{
		nl = 0;
		current = current->next;
	}
	while (current)
	{	
		printf("%s", current->str);
		if (current->next)
			printf(" ");
		current = current->next;
	}
	if (nl)
		printf("\n");
}

