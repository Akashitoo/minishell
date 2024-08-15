/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:17:24 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/19 16:52:00 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t				i;
	unsigned char		*dest;
	unsigned char		*src;

	dest = (unsigned char *) destination;
	src = (unsigned char *) source;
	if (!destination && !source)
		return (destination);
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}

/*#include <stdio.h>
#include <string.h>

int main() {
    char    source[] = "Hello World!";
    char    destination[200];
    char    destination2[200];

    // Copie les données de la source vers la destination
    printf("Valeur de retour ma fonction %p \n"
	,ft_memcpy(NULL, NULL, 80));
    printf("Valeur de retour fct de base %p \n"
	,memcpy(NULL, NULL, 80));
    // Affiche la destination
    printf("Ma fonction: %s\n",destination);
    printf("La fonction de base : %s \n",destination2);

    return 0;
}*/