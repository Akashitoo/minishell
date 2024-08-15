/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:07:00 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/23 14:45:57 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	countwords(const char *str, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	flag = 1;
	count = 0;
	while (str[i])
	{
		if (flag && str[i] != c)
		{
			count++;
			flag = 0;
		}
		if (str[i] == c)
			flag = 1;
		i++;
	}
	return (count + 1);
}

static int	sizeword(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_strncp(char *dest, const char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	*freedeb(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	res = (char **)malloc (countwords(s, c) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			res[j] = (char *)malloc((sizeword(s + i, c) + 1)
					* sizeof(char));
			if (!res[j])
				return (freedeb(res, j - 1));
			ft_strncp(res[j++], s + i, sizeword(s + i, c));
			i = i + sizeword(s + i, c);
		}
	}
	res[j] = NULL;
	return (res);
}

/*int main ()
{
	char *str = "      split       this for   me  !       ";
	int i;
	char **res;

	res = ft_split(str,' ');
	i = 0;
	while (i < countwords(str, ' '))
	{
		
		printf("=>%s<=\n",res[i]);
		i++;
	}
	return 0;
}*/