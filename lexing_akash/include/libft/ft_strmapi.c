/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:19:23 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/09 15:55:41 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*res;

	len = ft_strlen((char *)s);
	i = 0;
	res = (char *) malloc((len + 1) * sizeof(char const));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*char f(unsigned int i, char c)
{
	c = '0';
	return c;
}
#include <stdio.h>
int main ()
{
	char *str = "Le caca puang";

	printf("=>%s<=",ft_strmapi(str,f));
	return 0;
}*/