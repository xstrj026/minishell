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

void	debug_printf(char *str)
{
	if (DEBUG_MODE)
	{
		printf(RED"%s\n"RST, str);
	}
}

void	s_cmd_handler(t_list **list, t_token *operator_tok, t_array **m_array ,t_cmd cmd, t_env **env_var)
{
	t_array *array;

	array = *m_array;
	if (cmd == ECHO)
	{
		if(!(*list)->cmd_text)
			return ;
		char *str;
		
		str = (*list)->cmd_text;

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
//		ft_exit(&list, operator_tok, array, 1);
	}
	else if (cmd == EXPORT)
	{
		printf(Y"EXPORT\n"RST);
		ft_export(*list, env_var);
	}
	else if (cmd == UNSET)
		printf(Y"UNSET WAS CALLED\n"RST);
	else if (cmd == ENV)
	{
		printf("env, print enviroment variables\n");
		ft_print_env(*env_var);
	}
	else if (cmd == EXIT)
	{
		ft_exit(list, operator_tok, &array, 1, env_var);
	}
	debug_printf("\n\n                     KONTROLA\n\n");
	// ft_free_all(list, operator_tok, &array);
}



void	set_func(t_token *operator_tok, t_array **m_array, t_list** list, t_env **env_var) 
{
	t_array *array;

	array = *m_array;
	if (*list == NULL)
		return ;
	else if (if_cmd((*list)->branch, "echo"))
	{
		(*list)->comand = ECHO;
		(*list)->cmd_text = str_cut((*list)->branch,"echo");
	}
    else if (if_cmd((*list)->branch, "cd"))
	{
        (*list)->comand = CD;
		//list->cmd_text = str_cut(list->branch,"cd");
	}
    else if (if_cmd((*list)->branch, "pwd"))
        (*list)->comand = PWD;
    else if (if_cmd((*list)->branch, "export"))
	{
        (*list)->comand = EXPORT;
		(*list)->cmd_text = str_cut((*list)->branch,"export");
	}
    else if (if_cmd((*list)->branch, "unset"))
	{
        (*list)->comand = UNSET;
		(*list)->cmd_text = str_cut((*list)->branch,"unset");
	}
	else if (!(if_strwcmp((*list)->branch, "env")))
        (*list)->comand = ENV;
	else if (!(if_strwcmp((*list)->branch, "exit")))
        (*list)->comand = EXIT;
	s_cmd_handler(list, operator_tok, &array, (*list)->comand, env_var);
}