/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:30:35 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/23 14:45:06 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sizemall(int n)
{
	int				res;
	unsigned int	nbr;

	nbr = n;
	res = 2;
	if (n < 0)
	{
		res++;
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		res++;
	}
	return (res);
}

static char	*rempres(int n, char *res)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = n;
	if (n < 0)
	{
		res[i] = '-';
		i++;
		nbr = -n;
	}
	while (nbr > 9)
	{
		res[i] = '0' + nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	res[i] = '0' + nbr;
	res[i + 1] = '\0';
	return (res);
}

static char	*reverse(char *str, int n)
{
	int		i;
	int		len;
	char	c;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	if (n < 0)
		i++;
	while (i < len - 1)
	{
		c = str[i];
		str[i] = str[len - 1];
		str[len - 1] = c;
		i++;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*res;

	res = (char *) malloc(sizemall(n) * sizeof(char));
	if (!res)
		return (NULL);
	rempres(n, res);
	reverse(res, n);
	return (res);
}
/*#include <stdio.h>

int main ()
{
	printf("=>%s<=\n",ft_itoa(2147483647));
	return 0;
}*/