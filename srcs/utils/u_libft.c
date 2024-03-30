/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_libft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:32:35 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/03/30 21:55:13 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*str_cut(char *haystack,char *needle)
{
	int	i;
	int	j;

	if (!*needle || haystack == needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j])
			{
				j++;
				if (!needle[j])
				{
					while (haystack[i + j] == ' ' || haystack[i + j] == '\t')
						j++;
					return ((char *)&haystack[i+j]);
				}
			}
		}
		i++;
	}
	return (0);
}

int	if_cmd(char *haystack, char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (haystack[i] == ' ' || haystack[i] == '\t')
		i++;
	if (haystack[i] == needle[j])
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (!needle[j] && (haystack[i] == ' ' || !haystack[i]))
				return (1);
		}
	}
	return (0);
}

size_t	ft_strlcat_u(char *dst, char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		res_d;
	size_t		res_s;

	j = 0;
	if (size == 0 && dst == NULL)
		return (0);
	res_s = ft_strlen_u(src);
	i = ft_strlen_u(dst);
	res_d = ft_strlen_u(dst);
	if (size < 1)
		return (res_s + size);
	while (src[j] && i < (size - 1) && size != 0)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	if (size < res_d)
		return (res_s + size);
	else
		return (res_d + res_s);
}

size_t	ft_strlcpy_u(char *dst, char *src, size_t size)
{
	size_t		i;
	size_t		res;

	i = 0;
	res = 0;
	while (src[res])
	{
		res++;
	}
	if (size < 1)
		return (res);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}

int	if_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
