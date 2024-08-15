/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:32:13 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/21 13:47:33 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*pnt;

	pnt = pointer;
	i = 0;
	while (i < count)
	{
		pnt[i] = (unsigned char) value;
		i++;
	}
	return (pointer);
}

/*
#include <string.h>
#include <stdio.h>
int main ()
{
	int max =100;
	int pnt[max];
	int pn[max];
	int i = 0;

	ft_memset(pnt, 10, max);
	memset(pn,10,max);
	while (i< max/4)
	{
		printf("la chaine ainsi obtenu nous donne :%d\n",pnt[i]);
		printf("la chaine de la vrai fonction est :%d\n",pn[i]);
		printf ("i = %d\n",i);
		i++;
	}
	return 0;
}*/
