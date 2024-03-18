#include "../include/minishell.h"

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
	return (out);
}

char	**ft_operators(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] != '|' && str[i] != '>' && str[i] != '<'))
			i++;
		if (str[i] == '|' || ((str[i] == '>' && str[i + 1] == '>') || str[i] == '>' ) || ((str[i] == '<' && str[i + 1] == '<') || str[i] == '<'))
			wc++;
		while (str[i] && (str[i] == '|' || str[i] == '>' || str[i] == '<'))
			i++;
	}
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
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
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}