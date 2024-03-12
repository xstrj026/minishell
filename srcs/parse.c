#include "../include/minishell.h"

// int find_tkn(char *str, char *c) // c == | >> <<
// {
// 	int i;

// 	i = 0;
// 	while(str[i])
// 	{
// 		while (str[i++] == c[i])
// 			i++;
// 		if (!c[i])
// 		{
// 			return(c);
// 		}
// 	}
// 	return(0);
// }

// int find_tkn(char *str, char *c) // c == | >> <<
// {
// 	int i;

// 	i = 0;
// 	while(str[i])
// 	{
// 		while (str[i++] == c[i])
// 			i++;
// 		if (!c[i])
// 		{
// 			return(c);
// 		}
// 	}
// 	return(0);
// }

t_parsed parse_input(char *str) 
{
	t_parsed cmdWords; // Create an instance of the struct

    cmdWords.array_cmd = ft_cmd(str); 
    cmdWords.array_word = ft_words(str);

    return (cmdWords); // Return the struct (make sure to manage memory properly!)
}

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**ft_words(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '|' || str[i] == ' ' || str[i] == '\t' || str[i] == '>' || str[i] == '<'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != '|' && str[i] != ' ' && str[i] != '\t' && str[i] != '>' && str[i] != '<'))
			i++;
	}
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '|' || str[i] == ' ' || str[i] == '\t' || str[i] == '>' || str[i] == '<'))
			i++;
		j = i;
		while (str[i] && (str[i] != '|' && str[i] != ' ' && str[i] != '\t' && str[i] != '>' && str[i] != '<'))
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

void test_print(t_parsed cmdWords) {
    // Print commands
    printf("Commands:\n");
    for (int i = 0; cmdWords.array_cmd[i] != NULL; i++) {
        printf(RED"%d: %s\n"RST, i, cmdWords.array_cmd[i]);
    }

    // Print words
    printf("Words:\n");
    for (int i = 0; cmdWords.array_word[i] != NULL; i++) {
        printf(Y"%d: %s\n"RST, i, cmdWords.array_word[i]);
    }
}