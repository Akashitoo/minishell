/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_gone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:18:25 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/10 23:26:21 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	quote_gone_aux(char *str, char *new_str, int flag, int i)
{
	int		j;

	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' && flag != 1)
		{
			if (flag == -1)
				flag = 0;
			else
				flag = -1;
		}
		else if (str[i] == '"' && flag != -1)
		{
			if (flag == 1)
				flag = 0;
			else
				flag = 1;
		}
		else
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
}

int	quote_gone(char **str)
{
	int		size;
	char	*new_str;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	size = strlen(*str);
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (ft_putstr_fd("malloc err\n", 2), 0);
	quote_gone_aux(*str, new_str, flag, i);
	free(*str);
	*str = new_str;
	return (1);
}
