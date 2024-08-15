/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:43:39 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/17 16:39:40 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*res;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = (char *) malloc ((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (j < len && s[start + j])
	{
		res[j] = s[start + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
/*#include <stdio.h>
int main ()
{
	char *str = "le gros caca qui pue";
	printf("=>%s<= \n",ft_substr(str, 80,80));
	return 0;
}*/