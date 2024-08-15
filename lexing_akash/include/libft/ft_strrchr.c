/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:49:58 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/17 16:40:52 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		flag;
	char	*res;

	i = 0;
	flag = 0;
	c = c % 256;
	while (str[i])
	{
		if (str[i] == c)
		{
			res = (char *)str + i;
			flag = 1;
		}
		i++;
	}
	if (str[i] == (unsigned char) c)
	{
		res = (char *)str + i;
		flag = 1;
	}
	if (flag)
		return (res);
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int main()
{
	char *str = "tripouille";
	printf("Voici ma fonction : %s \n",ft_strrchr(str, 't' +  256));
	printf("La fonction de base : %s \n",strrchr(str, 't' + 256));
	return 0;
}*/