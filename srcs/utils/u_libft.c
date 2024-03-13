#include "../../include/minishell.h"


int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

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

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}