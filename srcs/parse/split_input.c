#include "../../include/minishell.h"

t_array parse_input(char *str) 
{
	t_array array; // Create an instance of the struct

    array.operator = ft_operators(str); 
    array.cmd = ft_cmd(str);

    return (array); // Return the struct (make sure to manage memory properly!)
}

char	**ft_cmd(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;

	if(!str)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == '|' || str[i] == '>' || str[i] == '<'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != '|' && str[i] != '>' && str[i] != '<'))
			i++;
	}
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '|' || str[i] == '>' || str[i] == '<'))
			i++;
		j = i;
		while (str[i] && (str[i] != '|' && str[i] != '>' && str[i] != '<'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	// printf("THIS IS ARRAY OF", RED" commands:\n"RST);
	// while (out)
	// {
	// 	printf("%s\n",out);
	// }
	return (out);
}

char	**ft_operators(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	char	**out;

	if (!str)
	{
		printf(RED"operator is missing\n"RST);
		return (NULL);
	}
	while (str[i])
	{
		while (str[i] && (str[i] != '|' && str[i] != '>' && str[i] != '<'))
			i++;
		if (str[i] == '|' || ((str[i] == '>' && str[i + 1] == '>') || str[i] == '>' ) || ((str[i] == '<' && str[i + 1] == '<') || str[i] == '<'))
			wc++;
		while (str[i] && (str[i] == '|' || str[i] == '>' || str[i] == '<'))
			i++;
	}
	out = (char **)safe_malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] != '|' && str[i] != '>' && str[i] != '<')) 
			i++;
		j = i;
		while (str[i] && (str[i] == '|' || str[i] == '>' || str[i] == '<'))
			i++;
		if (i > j)
		{
			out[k] = (char *)safe_malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	// printf("THIS IS ARRAY OF OPERATORS:\n");
	// while (out)
	// {
	// 	printf("%s\n",out);
	// }
	return (out);
}