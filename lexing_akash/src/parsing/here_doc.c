/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:25:23 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/26 16:21:52 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int list_size_str(t_token *list)
{
	int 	res;
	t_token *temp;

	temp = list;
	res = 0;
	while (temp)
	{
		res += ft_strlen(temp->str);
		temp = temp->next;
	}
	return (res);
}
char  *list_to_str(t_token *list)
{
	char *res;
	t_token *temp;
	int		i;
	int		j;

	//printf("petit check\n");
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

void	here_doc2_bis(char *str, t_token **token, t_token **list)
{
	*token = malloc(sizeof(t_token));
	(*token)->str = str;
	(*token)->next = NULL;
	ft_lstadd_tok(list, *token);
}
void	here_doc2_tres(char *str, int *flag)
{
	free(str);
	*flag = 0;
}
char	*here_doc2(char *limiter)
{
	char	*str;
	int		flag;
	t_token	*token;
	t_token	*list;

	flag = 1;
	list = NULL;
	while (flag)
	{
		ft_putstr_fd(">", 1);
		str = get_next_line(STDIN_FILENO);
		if (str == NULL)
			return (freetokens(list), NULL);	
		if (ft_strncmp(str, limiter, ft_strlen(limiter)) == 0
			&& str[ft_strlen(limiter)] == '\n')
			here_doc2_tres(str, &flag);
		else
			here_doc2_bis(str, &token, &list);
	}
	str = list_to_str(list);
	freetokens(list);
	if (str == 	NULL)
		return (NULL);
	return (str);
}

// int	here_doc(t_data *parsing)
// {
// }
