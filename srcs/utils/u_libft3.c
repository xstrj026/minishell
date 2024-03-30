/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_libft3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:32:21 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/03/30 21:35:46 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*tmp_str;
	char			tmp_c;
	size_t			i;

	tmp_str = (unsigned char *)str;
	tmp_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		tmp_str[i] = tmp_c;
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}*/
/* porovnavani 2 stringu, na zaklade posledniho znaku shodujiciho
se stringu, retun 0 if is the same*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	msg_error("pouzivam ft_strcmp");
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strcmp2(char *s1, char *s2)
{
	int	i;

	i = 0;
	msg_error("pouzivam ft_strcmp222222222");
	if (s1 == NULL)
		msg_error("s1 in ft_strcmp is NULL");
	if (s2 == NULL)
		msg_error("s2 in ft_strcmp is NULL");
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	if_strwcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] == ' ' || s1[i] == '\t')
		i++;
	while (s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0')
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}
