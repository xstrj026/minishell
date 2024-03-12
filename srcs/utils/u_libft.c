#include "../../include/minishell.h"


int	ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	if (!*needle)
		return (0);
	if(haystack == needle)
		return (1);
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
					return(1);
			}
		}
		i++;
	}
	return (0);
}