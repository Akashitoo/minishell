/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:41:39 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/16 17:42:54 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strimd(char const *s1, char const *set)
{
	int	i;
	int	supp;

	i = 0;
	supp = 0;
	while (set[i])
	{
		if (set[i] == s1[supp])
		{
			supp++;
			i = -1;
		}
		i++;
	}
	return (supp);
}

int	ft_strimf(char const *s1, char const *set)
{
	int	i;
	int	supp;
	int	s1len;

	i = 0;
	supp = 0;
	s1len = ft_strlen((char *)s1);
	while (set[i])
	{
		if (set[i] == s1[s1len - supp - 1])
		{
			supp++;
			i = -1;
		}
		i++;
	}
	return (supp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	int			i;
	size_t		deb;
	int			fin;

	if (!s1[0] || !set[0])
		return (ft_strdup(s1));
	deb = ft_strimd(s1, set);
	fin = ft_strimf(s1, set);
	if (deb == ft_strlen(s1))
		deb = 0;
	res = (char *)malloc ((ft_strlen(s1) - deb - fin + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (deb < ft_strlen((char *)s1) - fin)
	{
		res[i] = s1[deb];
		i++;
		deb++;
	}
	res[i] = '\0';
	return (res);
}
/*#include <stdio.h>
int main ()
{
	char *str = "  \t \t \n   \n\n\n\t";
	char *str2 = " \n\t";

	printf("=>%s<=\n", ft_strtrim(str,str2));
	//printf("str:\n=>%s<=\n",str);
}*/