/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:51:44 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/19 16:55:51 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*str, size_t	n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)str;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}

/*#include <string.h>
#include <stdio.h>
int main ()
{
	int max = 10;
	int pnt[max];
	int pn[max];
	int i = 0;

	ft_bzero(pnt, max);
	while (i< max)
	{
		printf("la chaine ainsi obtenu nous donne :%d\n",pn[i]);
		printf ("i = %d\n",i);
		i++;
	}
	i = 0;
	bzero(pn, max);
	while (i < max )
	{
		printf("la chaine de la vrai fonction est :%d\n",pn[i]);
		printf ("i = %d\n",i);
		i++;
	}
	return 0;
}*/