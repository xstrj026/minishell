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

// char	*ft_putstr(char *str, char *dest)
// {

// }

/* porovnavani 2 stringu, na zaklade posledniho znaku shodujiciho se stringu, retun 0 if is the same*/
int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int ft_strcmp2(char *s1, char *s2)
{
	int i;

	i = 0;
	if (s1 == NULL)
	{
		printf("s1 in ft_strcmp is NULL");
	}
	if (s1 == NULL)
	{
		printf("s1 in ft_strcmp is NULL");
	}
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && s1[i] && s2[i])
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

char *ft_strcpy(char *dst, char *src)
{
	int i;
	
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
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

int	if_n_cmd(char *haystack,char *needle)
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
				if (!needle[j] && haystack[j] == 'n')
				{
					while(haystack[j] == 'n')
						j++;
					if(haystack[j] == ' ')
						return (1);
				}
				if (!needle[j] && (haystack[i] == ' ' || !haystack[i]))
					return (1);
			}
	}
	return (0);
}

char	*echo_n_cut(char *haystack,char *needle)
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
					while(haystack[i + j] == 'n')
						j++;
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

int if_strchr(char *str, char c)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return(1);
		i++;
	}
	return(0);
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

