/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_libft2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:30:32 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/03/30 21:54:10 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	ft_strlen_u(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_u(char *s1, char *s2)
{
	char		*dst;
	size_t		s1_len;
	size_t		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen_u(s1);
	s2_len = ft_strlen_u(s2);
	dst = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy_u(dst, s1, s1_len + 1);
	ft_strlcat_u(dst + (s1_len), s2, s2_len + 1);
	return (dst);
}

int	if_n_cmd(char *haystack, char *needle)
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
			if (!needle[j] && haystack[j] == 'n')
			{
				while (haystack[j] == 'n')
					j++;
				if (haystack[j] == ' ')
					return (1);
			}
			if (!needle[j] && (haystack[i] == ' ' || !haystack[i]))
				return (1);
		}
	}
	return (0);
}

char	*part_echo_n_cut(char *haystack, char *needle, int i, int j)
{
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j])
			{
				j++;
				if (!needle[j])
				{
					while (haystack[i + j] == 'n')
						j++;
					while (haystack[i + j] == ' ' || haystack[i + j] == '\t')
						j++;
					return ((char *)&haystack[i + j]);
				}
			}
		}
		i++;
	}
	return (0);
}

char	*echo_n_cut(char *haystack, char *needle)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!*needle || haystack == needle)
		return ((char *)haystack);
	ret = part_echo_n_cut(haystack, needle, i, j);
	if (ret != 0)
		return (ret);
	return (0);
}


/* int main () 
{
	char *haystack = "echo ";
	char *needle = "echo";
	char *res;

	res = ft_strjoin_u(haystack, needle);
	printf("String: %s\n", res);
	return(0);
} */

