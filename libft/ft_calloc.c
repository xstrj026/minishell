/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:49:07 by ytsyrend          #+#    #+#             */
/*   Updated: 2023/03/30 15:51:49 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*addr;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	addr = malloc(nitems * size);
	if (!addr)
	{
		return (NULL);
	}
	ft_bzero(addr, size * nitems);
	return (addr);
}