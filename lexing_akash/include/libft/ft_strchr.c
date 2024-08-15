/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:44:08 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/09 16:36:17 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (unsigned char) c)
		return ((char *)str + i);
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	char *str = "Hello World !!";
	printf("Voici ma fonction : %s \n",ft_strchr(str, 500));
	printf("La fonction de base : %s \n",strchr(str, 500));
	return 0;
}*/
