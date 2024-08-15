/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:26:36 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/20 11:44:12 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;
	size_t	lensrc;

	if ((dest == NULL || src == NULL) && size == 0)
		return (0);
	lendest = ft_strlen((const char *)dest);
	lensrc = ft_strlen((const char *)src);
	i = 0;
	if (size <= lendest)
		return (size + lensrc);
	while (src[i] && (i + lendest) < (size - 1))
	{
		dest[lendest + i] = src [i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (lendest + lensrc);
}
