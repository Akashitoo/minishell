/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:36:39 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/26 16:20:46 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int which_op(char *str)
{
	if (!str[0])
		return (UNDEFINED);
	if (!ft_strncmp("<", str, 2))
		return (INPUT);
	if (!ft_strncmp("|", str , 2))
		return (PIPE);
	if (!ft_strncmp(">", str , 2))
		return (OUTPUT);
	if(str[1])
	{
		if (!ft_strncmp("<<", str, 3))
			return (HERE_DOC);
		if (!ft_strncmp(">>", str, 3))
			return (APPEND);
	}
	return (UNDEFINED);
}



t_token *create_token_parsing(t_data *parsing, t_token	*new_token)
{
	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (ft_putstr_fd("error malloc create_token\n", 2), NULL);
	new_token->str = (char *)malloc (sizeof(char) * (parsing->i + 2 - parsing->last_tok));
	if (!new_token->str)
		return (ft_putstr_fd("error malloc create_token\n", 2), free(new_token), NULL);
	return(new_token);
}

int	which_token_id(t_data *parsing, char *str)
{
	if (is_op(str[0]))
		return  (which_op(str));
	else if (parsing->is_last_word || str[0] == '\"' || str[0] == '\'')
		return (WORD);
	else 
		return (UNDEFINED);
}

int	create_token(t_data *parsing)
{
	int		index;
	t_token	*new_token;
	int	i;

	i = 0;
	new_token = NULL;
	new_token = create_token_parsing(parsing, new_token);
	if (!new_token)
		return (0);
	if (parsing->i < parsing->last_tok)
		return (printf("i plus petit que last tok\nvaleur de i :%d\n val de last_tok : %d\n",parsing->i, parsing->last_tok), 1);
	index = parsing->last_tok;
	while (index <= parsing->i)
	{
		if ((index != parsing->i && index != parsing->last_tok) || !is_blank(parsing->str[index]))
			new_token->str[i++] = parsing->str[index]; 
		index++;
	}
	new_token->str[i] = '\0';
	new_token->type = which_token_id(parsing, new_token->str);
	new_token->fd = 0;
	new_token->next = NULL;
	ft_lstadd_tok(&parsing->token_list, new_token);
	parsing->last_tok = parsing->i + 1;
	parsing->flag = 0;
	return (1);
}
