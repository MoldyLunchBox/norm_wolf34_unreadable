/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:28:39 by yoelguer          #+#    #+#             */
/*   Updated: 2022/05/21 12:09:42 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_src;
	unsigned char	*p_dest;

	i = 0;
	p_src = (unsigned char *)src;
	p_dest = (unsigned char *)dst;
	while (i < n)
	{
		if (p_src[i] == (unsigned char)c)
		{
			p_dest[i] = p_src[i];
			return ((void *)p_dest + i + 1);
		}
		p_dest[i] = p_src[i];
		i++;
	}
	return (NULL);
}
