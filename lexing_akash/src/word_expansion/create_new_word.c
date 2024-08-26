/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:48:19 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/26 15:22:18 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void create_new_word2(t_word_exp *word_ext, int *i)
{
	int	y;

	y = 0;
	if (word_ext->var_content)
	{
		y = 0;
		while(word_ext->var_content[y])
		{
			word_ext->new_word[*i + y] = word_ext->var_content[y];
			printf("val num%d de new word : %c\n", *i + y, word_ext->new_word[*i + y]);
			y++;
		}
	}
	*i += y - 1;
	
}
int create_new_word3(t_word_exp *word_ext, int *seen, int *i, int *j)
{
	if (word_ext->word[*i] == '$' && *seen == word_ext->$to_ignore)
	{
		create_new_word2(word_ext, j);
		*seen = *seen + 1;
		*i += word_ext->size_var_name - 1;
	}
	else if (word_ext->word[*i] == '$')
	{
		seen++;
		word_ext->new_word[*j] = word_ext->word[*i];
		*j = *j + 1;
		*i = *i + 1;
		if (!word_ext->word[*i])
			return (0);
		word_ext->new_word[*j] = word_ext->word[*i];
	}
	else
		word_ext->new_word[*j] = word_ext->word[*i];
	return (1);
}
void create_new_word(t_word_exp *word_ext)
{
	int		i;
	int		j;
	int		seen;

	i = 0;
	j = 0;
	seen = 0;

	while (word_ext->word[i])
	{
		create_new_word3(word_ext, &seen, &i, &j);
		i++;
		j++;
	}
	word_ext->new_word[j] = word_ext->word[i];
}
