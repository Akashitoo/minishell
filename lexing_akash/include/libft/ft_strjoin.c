/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:19:35 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/16 12:21:40 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		size;
	int		i;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	res = (char *) malloc(size * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	size = 0;
	while (s2[size])
	{
		res[i] = s2[size];
		i++;
		size++;
	}
	res[i] = '\0';
	return (res);
}
/*#include <stdio.h>
int main ()
{
	char *str1 = "";
	char *str2 = "g";

	printf("%s\n",ft_strjoin(str1, str2));
	return 0;
}*/