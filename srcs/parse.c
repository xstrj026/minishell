#include "../include/minishell.h"

t_parsed parse_input(char *str) 
{
	t_parsed cmdWords; // Create an instance of the struct

    cmdWords.operator = ft_cmd(str); 
    cmdWords.cmd = ft_words(str);

    return (cmdWords); // Return the struct (make sure to manage memory properly!)
}

char	**ft_words(char *str)
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

char	**ft_cmd(char *str)
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