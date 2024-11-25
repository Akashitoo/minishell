/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:46:57 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/10 22:52:34 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_char_name(char c)
{
	if (c == '_')
		return (1);
	if (c <= '9' && c >= '0')
		return (1);
	if (c <= 'Z' && c >= 'A')
		return (1);
	if (c <= 'z' && c >= 'a')
		return (1);
	return (0);
}

int	get_size_name_var(char *str)
{
	int	res;

	res = 0;
	if ((str[res] <= '9' && str[res] >= '0') || str[res] == '?')
		return (1);
	while (str[res])
	{
		if (!is_char_name(str[res]))
			return (res);
		res++;
	}
	return (res);
}

char	*get_name_var(char *str)
{
	int		i;
	char	*name_var;
	int		size;

	size = get_size_name_var(str) + 1;
	name_var = (char *)malloc(sizeof(char) * size);
	if (!name_var)
		return (NULL);
	name_var[size - 1] = '\0';
	i = 0;
	if ((str[i] <= '9' && str[i] >= '0') || str[i] == '?')
	{
		name_var[i] = str[i];
		return (name_var);
	}
	while (str[i])
	{
		if (!is_char_name(str[i]))
			return (name_var);
		name_var[i] = str[i];
		i++;
	}
	return (name_var);
}

void	get_size_new_str(t_word_exp *word_ext)
{
	if (!word_ext->var_content)
		word_ext->size_var_content = 0;
	else
		word_ext->size_var_content = ft_strlen(word_ext->var_content) + 1;
	word_ext->size_var_name = (ft_strlen(word_ext->var_name) + 1);
	word_ext->size_word = ft_strlen(word_ext->word);
	word_ext->size_new_word = word_ext->size_word
		-word_ext->size_var_name + word_ext->size_var_content;
}

int	get_value(t_word_exp *word_ext, int i)
{
	word_ext->var_name = get_name_var(word_ext->word + i);
	if (!word_ext->var_name)
		return (0);
	word_ext->var_content = my_getenv(word_ext);
	if (!word_ext->var_content)
		return (free(word_ext->var_name), 0);
	get_size_new_str(word_ext);
	word_ext->new_word = (char *) malloc(sizeof(char)
			*(word_ext->size_new_word + 1));
	if (!word_ext->new_word)
		return (free(word_ext->var_name), free(word_ext->var_content), 0);
	word_ext->new_word[word_ext->size_new_word] = '\0';
	create_new_word(word_ext);
	free(word_ext->var_name);
	free(word_ext->var_content);
	return (1);
}
