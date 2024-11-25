/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:16:53 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/10 15:57:18 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*my_getenv_success(char *str_env, char *str_var)
{
	char	*res;
	int		j;
	int		i;

	res = malloc(sizeof(char) * (strlen(str_env) + 1));
	if (!res)
		return (ft_putstr_fd("Malloc failed\n", 2), NULL);
	j = 0;
	i = strlen(str_var) + 1;
	while (str_env[i])
		res[j++] = str_env[i++];
	res[j] = '\0';
	return (res);
}

char	*my_getenv(t_word_exp *word_exp)
{
	t_env	*current;
	char	*res;

	current = word_exp->environ;
	while (current)
	{
		if (!ft_strncmp(word_exp->var_name, current->str,
				strlen(word_exp->var_name)))
		{
			if (current->str[strlen(word_exp->var_name)] == '=')
				return (my_getenv_success(current->str, word_exp->var_name));
		}
		current = current->next;
	}
	res = malloc(sizeof(char));
	res[0] = '\0';
	return (res);
}
