/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:26:16 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/10 16:31:41 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern volatile sig_atomic_t	g_signal_state;

int	list_size_str(t_token *list)
{
	int		res;
	t_token	*temp;

	temp = list;
	res = 0;
	while (temp)
	{
		res += ft_strlen(temp->str);
		temp = temp->next;
	}
	return (res);
}

char	*list_to_str(t_token *list)
{
	char	*res;
	t_token	*temp;
	int		i;
	int		j;

	temp = list;
	i = 0;
	j = 0;
	res = (char *)malloc((list_size_str(list) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (temp)
	{
		while (temp->str[i])
		{
			res[i + j] = temp->str[i];
			i++;
		}
		j = j + i;
		i = 0;
		temp = temp->next;
	}
	res[j] = '\0';
	return (res);
}
