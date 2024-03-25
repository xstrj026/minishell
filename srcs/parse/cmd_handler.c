#include "../../include/minishell.h"

char* recursive_process_echo(char **str)
{
    if (if_n_cmd(*str, "-n"))
    {
        *str = echo_n_cut(*str, "-n");
		 return (recursive_process_echo(str));
    }
	else
    {
        return (*str);
    }
}



char	*ft_save_key(char *str)
{

}

char	*ft_save_value(char *str)
{
	int		i;
	char	*value;

	while (str[i] != '=')
		i++;
	i++;
	while (str[i])
	{
		
	}
	
}

void	ft_export(t_list *list)
{
	char	*str;
	t_env	*node;
	int		i;

	i = 0;
	str = list->cmd_text;
	node = (t_env *)malloc(sizeof (t_env));

	while (str[i] && ft_isalpha(str[i]))
	{
		i++;
	}
	node->key = malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i] && ft_isalpha(str[i]))
	{
		node->key[i] = str[i];
		i++;
	}
	node->key[i] = '\0';
	
	i = 0;
	int j = 0;
	int	size;
	while (str[i] && str[i] != '=')
	{
		i++;
	}
	if (str[i] == '=')
	{
		i++;
	}
	j = i;
	// if(quotes)
	// {

	// }
	// else
	{
	while (str[i] && ft_isprint(str[i]))
	{
		i++;
	}
	size = i - j;
	i = j;
	node->value = (char *)malloc((size + 1) * sizeof(char));
	if (node.value == NULL)
	{
		printf("error with malloc\n")
	}
	while (str[i] && ft_isprint(str[i]))
	{
		node->value[i] = str[i];
		i++;
	}
	node->key[i] = '\0';
	}
	node->next = NULL;
}

void	s_cmd_handler(t_list *list, char *input, t_token *operator_tok, t_array array ,t_cmd cmd)
{
	if(!list->cmd_text)
		return ;
	if (cmd == ECHO)
	{
		char *str;
		
		str = list->cmd_text;

		if(quote_handle(str))
			return ;
		if (if_n_cmd(str, "-n"))
		{
			str = recursive_process_echo(&str);
			print_segments(str);
			if(one_case(str))
				return ;
			echo_print(str);
		}
		else
		{
			if (one_case(str))
			{
				write(1, "\n", 1);
				return ;
			}
			echo_print(str);
			write(1, "\n", 1); // New line after the final output
		}
	}
	else if (cmd == CD)
		printf(Y"Dont worry and be haaapy\n"RST);
	else if (cmd == PWD)
	{
		ft_pwd();
	}
	else if (cmd == EXPORT)
	{
		printf(Y"EXPORT\n"RST);
		ft_export(list);
	}
	else if (cmd == UNSET)
		printf(Y"Aaaaall you neeeeed is love\n"RST);
	else if (cmd == ENV)
	{
		printf("env");
	}
	else if (cmd == EXIT)
	{
		ft_exit(&list, input, operator_tok, array, 1);
	}
}

void	set_func(char *input, t_token *operator_tok, t_array array, t_list* list) 
{
	if (list == NULL)
		return ;
	else if (if_cmd(list->branch, "echo"))
	{
		list->comand = ECHO;
		list->cmd_text = str_cut(list->branch,"echo");
	}
    else if (if_cmd(list->branch, "cd"))
	{
        list->comand = CD;
		//list->cmd_text = str_cut(list->branch,"cd");
	}
    else if (if_cmd(list->branch, "pwd"))
        list->comand = PWD;
    else if (if_cmd(list->branch, "export"))
	{
        list->comand = EXPORT;
		list->cmd_text = str_cut(list->branch,"export");
	}
    else if (if_cmd(list->branch, "unset"))
	{
        list->comand = UNSET;
		list->cmd_text = str_cut(list->branch,"unset");
	}
    else if (!(if_strwcmp(list->branch, "env")))
        list->comand = ENV;
    else if (!(if_strwcmp(list->branch, "exit")))
        list->comand = EXIT;
	s_cmd_handler(list, input, operator_tok, array, list->comand);
}