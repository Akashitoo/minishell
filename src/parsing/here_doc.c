/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:25:23 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/12 17:45:18 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	here_doc2_bis(char *str, t_token **token, t_token **list)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != '\n')
		printf("\n");
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

char	*case_eof(void)
{
	char	*res;

	res = malloc(sizeof(char));
	res[0] = '\0';
	return (res);
}

char	*here_doc2_aux(char *str, t_token *list)
{
	signal_init_basic();
	str = list_to_str(list);
	freetokens(list);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*here_doc(char *limiter)
{
	char	*str;
	int		flag;
	t_token	*token;
	t_token	*list;

	flag = 1;
	list = NULL;
	signal_init_here_doc();
	while (flag)
	{
		if (flag != 18)
			ft_putstr_fd(">", 1);
		else
			flag = 1;
		str = get_next_line(STDIN_FILENO);
		if (str == NULL)
			flag = 18;
		else if (ft_strncmp(str, limiter, ft_strlen(limiter)) == 0
			&& str[ft_strlen(limiter)] == '\n')
			here_doc2_tres(str, &flag);
		else
			here_doc2_bis(str, &token, &list);
	}
	return (here_doc2_aux(str, list));
}
