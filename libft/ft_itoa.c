/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:40:48 by yoelguer          #+#    #+#             */
/*   Updated: 2022/05/21 12:30:21 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_print(int i, int p, int c, char *str)
{
	while (--i >= 0)
	{
		str[i] = (p % 10) + '0';
		p /= 10;
	}
	if (c < 0)
		str[0] = '-';
	return (str);
}

char	*str(int i, int p, int c)
{
	char	*str;

	str = (char *)malloc((i + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	str[i] = '\0';
	ft_print(i, p, c, str);
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		p;
	int		c;

	i = 1;
	c = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		i++;
		n = -n;
	}
	p = n;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (str(i, p, c));
}
