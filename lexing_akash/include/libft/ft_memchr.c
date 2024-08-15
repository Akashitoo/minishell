/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:32:24 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/13 15:57:28 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*list;
	unsigned char	elmt;

	list = (unsigned char *)str;
	elmt = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (list[i] == elmt)
			return (list + i);
		i++;
	}
	return (NULL);
}
/*#include <string.h>
#include <stdio.h>
int main ()
{
	char *src = "Voici la source";
	printf("Ma fct: %s\n",(char *) ft_memchr(src, 'r', 5));
	printf("La vrai fct: %s \n", (char *) memchr(src, 'r', 5));
	return 0;
}*/