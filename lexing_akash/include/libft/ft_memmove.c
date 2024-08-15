/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:41:38 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/23 14:53:59 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	size_t				i;
	unsigned char		*dest;
	unsigned char		*src;

	if (!destination && !source)
		return (destination);
	src = (unsigned char *)source;
	dest = (unsigned char *) destination;
	if (source > destination)
	{
		i = -1;
		while (++i < size)
			dest[i] = src[i];
	}
	else
	{
		while (size > 0)
		{
			dest[size - 1] = src[size - 1];
			size--;
		}
	}
	return (destination);
}
/*#include <stdio.h>
#include <string.h>
int main ()
{
    char source[] = "Hello, world!";
    char destination[200];
    char destination2[200];

    // Copie les données de la source vers la destination
    ft_memmove(destination, source, strlen(source) + 1);
    memmove(destination2, source, strlen(source) + 1);
    // Affiche la destination
    printf("Ma fonction: %s\n", destination);
    printf("Fonction de base: %s \n", destination2);

    return 0;
}*/