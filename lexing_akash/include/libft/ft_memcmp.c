/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:42:51 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/13 15:22:03 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*list1;
	unsigned char	*list2;

	list1 = (unsigned char *) str1;
	list2 = (unsigned char *) str2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (list1[i] != list2[i])
			return (list1[i] - list2[i]);
		i++;
	}
	return (0);
}
/*#include <string.h>
#include <stdio.h>
int main ()
{
	char *str1 = "ma str";
	char *str2 = "4a sol";
	printf ("voici ma fct : %d\n", ft_memcmp(str1, str2,1));
	printf("la fct de base :%d\n", memcmp(str1,str2,1));
	return 0;
}*/
