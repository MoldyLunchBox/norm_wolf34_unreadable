/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <amya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:56:12 by yoelguer          #+#    #+#             */
/*   Updated: 2022/05/21 12:02:05 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n_bytes)
{
	size_t	i;
	char	*p_mem;

	i = 0;
	p_mem = (char *)s;
	while (i < n_bytes)
	{
		p_mem[i] = 0;
		i++;
	}
}
