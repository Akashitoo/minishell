/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:29:51 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/17 11:36:59 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	if (size && SIZE_MAX / size < nmemb)
		return (NULL);
	temp = (unsigned char *)malloc(size * nmemb);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return ((void *)temp);
}
