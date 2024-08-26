/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:52:11 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/26 15:21:49 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*doooonc pour recapituler je recois ici une liste chainee avec des chaines de caactere et leur types respectif*/
/*dans un premier temps on va lire la doc et faire un schema de quelle etapes on peut mettre en place*/
/*donc je vais ecrire ici tous ce que je vois pour faire un recap et surtout faire en sorte d'avancer*/
/*donc deja une separation est faite entre les mots classique et les caracteres specifiques
a prendre en compte : les mots reserve ne sont reconnu que dans certaines positions
ensuite on gere les redirections de sortie ou d'entree en tout genre y compris les here_doc
ensuite */

#include "../../include/minishell.h"
/*ici on creer une fonction qui est cense envoyer l'erreur et sur le bon endroit*/

void print_error_next(t_data *parsing)
{
	t_token *token;

	token = go_through_list(parsing->token_list, parsing->i);
	if (token->next)
	{
		ft_putstr_fd("bash: syntax error near unexpected token '", 2);
		ft_putstr_fd(token->next->str, 2);
		ft_putstr_fd("'\n",2);
	}
	else
	{
		ft_putstr_fd("bash: syntax error near unexpected token '", 2);
		ft_putstr_fd("newline", 2);
		ft_putstr_fd("'\n",2);
	}/*ici definir si le \n est envoyer a chaque fin de ligne*/
}

void print_error(t_data *parsing)
{
	t_token *token;

	token = go_through_list(parsing->token_list, parsing->i);
	ft_putstr_fd("bash: syntax error near unexpected token '", 2);
	ft_putstr_fd(token->str, 2);
	ft_putstr_fd("'\n",2);

}
char *rm_quote(char *str)
{
	int		i;
	int		size;
	char	*res;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			size++;
		i++;
	}
	i = 0;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (ft_putstr_fd("malloc rm quote\n", 2), NULL);
	size = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			res[size++] = str[i];
		i++;
	}
	res[size] = '\0';
	return (res);
}
int	pre_here_doc(t_token *temp)
{
	int	i;
	char *new_str;

	i = 0;
	while (temp->str[i])
	{
		if (temp->str[i] == '\'' || temp->str[i] == '\"')
			temp->type = HD_CORRUPTED;
		i++;
	}
	if (temp->type != HD_CORRUPTED)
		return (1);
	new_str = rm_quote(temp->str);
	if (!new_str)
		return (0);
	free(temp->str);
	temp->str = new_str;
	printf("########%s#######\n", temp->str);
	return (1);
	
}
int ft_parsing2(t_data *parsing, t_token *temp)
{
	char	*str;

	if (temp->next->type == WORD)
	{
		if (!pre_here_doc(temp->next))
			return (0);
		str = here_doc2(temp->next->str);
		if (!str)
			return (0);
		free(temp->next->str);
		temp->next->str = str;
	}
	else
		return (print_error_next(parsing), 0);
	return (1);
}
int ft_parsing(t_data *parsing)
{
	t_token *temp;

	temp = parsing->token_list;
	parsing->i = 0;
	if (temp->type == PIPE)
		return (print_error(parsing), 0);
	while (temp)
	{
		if (temp->type == HERE_DOC && temp->next)
		{
			if (!ft_parsing2(parsing, temp))
				return (0);
		}
		else if (temp->type > WORD && temp->type < PIPE)
		{
			if (!temp->next || temp->next->type != WORD)
				return (print_error_next(parsing), 0);
		}
		parsing->i++;
		temp = temp->next;
	}
	return (1);
}

