/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:38:52 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/09 16:36:26 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
	{
		return (0);
	}
	return (1024);
}
/*#include <ctype.h>
#include <stdio.h>
int main ()
{
	int i;
	i = 0;
	while(i< 127)
	{
		printf("ma fonction que j'ai fait: %d\n",ft_isalpha(i));
		printf("La fonction de base : %d\n",isalpha(i));
		i++;
	}
	return 0;
}*/
