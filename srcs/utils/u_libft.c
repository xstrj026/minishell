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

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

int if_strwcmp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(s1[i] == ' ' || s1[i] == '\t')
		i++;
	while (s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0')
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}



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
					while(haystack[i + j] == ' ' || haystack[i + j] == '\t')
						j++;
					return ((char *)&haystack[i+j]);
				}
			}
		}
		i++;
	}
	return (0);
}

int	if_cmd(char *haystack,char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(haystack[i] == ' ' || haystack[i] == '\t')
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

/*int main () 
{
	char *haystack = "echo";
	char *needle = "echo";
	int res;

	res = if_cmd(haystack, needle);
	printf("The substring is: %d\n", res);
	return(0);
}*/