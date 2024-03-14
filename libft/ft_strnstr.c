/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:40:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/03/14 11:58:53 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!*needle || !len || haystack == needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (i + j < len && haystack[i + j] == needle[j])
			{
				j++;
				if (!needle[j])
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}

/*int main () 
{
const char haystack[20] = "TutorialsPoint";
const char needle[10] = "to";
char *result;

result = ft_strnstr(haystack, needle, 2);
printf("The substring is: %s\n", result);
return(0);
}*/

// char	*ft_sstr(const char *haystack, const char *needle, size_t len)
// {
// 	unsigned int	i;
// 	unsigned int	j;

// 	if (!*needle || !len || haystack == needle)
// 		return ((char *)haystack);
// 	i = 0;
// 	while (haystack[i] != '\0' && i < len)
// 	{
// 		j = 0;
// 		if (haystack[i] == needle[j])
// 		{
// 			while (i + j < len && haystack[i + j] == needle[j])
// 			{
// 				j++;
// 				if (!needle[j])
// 					return ((char *)&haystack[i]);
// 			}
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int main () 
// {
// 	const char haystack[20] = "TutorialsPoint";
// 	const char needle[10] = "to";
// 	char *result;

// 	result = ft_sstr(haystack, needle, 2);
// 	printf("The substring is: %s\n", result);
// 	return(0);
// }