#include "../../include/minishell.h"

bool	operator_exist(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i])
		{
			if (str[i] == '|' || ((str[i] == '>' && str[i + 1] == '>') || str[i] == '>' ) || ((str[i] == '<' && str[i + 1] == '<') || str[i] == '<'))
			{
				printf("operator contains this: %c\n", str[i]);
				return(true);
			}
		}
		i++;
	}
	return (false);
}


t_array *parse_input(char *str, t_array **main_array) 
{
	t_array	*array; // Create an instance of the struct
	int i;

	array = *main_array;
	i = 0;
	if (str == NULL || str[i] == '\0')
	{
		array->command_exist = false;
		array->command_exist = false;
		array->cmd = NULL;
		array->operator = NULL;
		i++;
		// array->operator[i] = NULL;
		printf("readline is empty\n pointer of output of readline is: %p\n", str);
		return (array);
	}
	printf("this is the output of readline: %s\n", str);
	array->cmd = ft_cmd(str);
	array->command_exist = true;
	//kontrola jestli existuje operator
	if (operator_exist(str) == true)
	{
		array->operator_exist = true;
		array->operator = ft_operators(str);
	}
	else
	{
		array->operator_exist = false;
		array->operator = NULL;
	}
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
	char **out = (char **)calloc((wc + 1), sizeof(char *));
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
			out[k] = (char *)calloc(((i - j) + 1), sizeof(char));
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

	printf("\n%s\n", str);
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

	out = (char **)calloc((wc + 1), sizeof(char *));
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
			out[k] = (char *)calloc(((i - j) + 1), sizeof(char));
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