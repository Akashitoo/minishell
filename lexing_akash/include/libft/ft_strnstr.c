/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:53:05 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/21 14:07:13 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char *)big);
	if (!len)
		return (NULL);
	if (ft_strlen(big) < len)
		len = ft_strlen(big);
	while (i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && i + j < len && little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
int main ()
{
	char *str1 = "lorem ipsum dolor sit amet";
	char *str2 = "ipsumm";

	printf("Voici ma fct : %s\n",ft_strnstr(str1,str2,50));
	printf("La fct de base:%s\n", strstr(str1,str2));
	return 0;
}*/
