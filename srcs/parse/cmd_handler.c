#include "../../include/minishell.h"



void	s_cmd_handler(t_list **list, char *input, t_token *operator_tok, t_array array ,t_cmd cmd)
{
	if (cmd == ECHO)
		printf(Y"I beleive i can flyyyyyyy and command echo \n"RST);
	else if (cmd == CD)
		printf(Y"Dont worry and be haaapy\n"RST);
	else if (cmd == PWD)
	{
		ft_pwd();
	}
	else if (cmd == EXPORT)
		printf(Y"Rideeers on the stoooooorm\n"RST);
	else if (cmd == UNSET)
		printf(Y"Aaaaall you neeeeed is love\n"RST);
	else if (cmd == ENV)
		printf(Y"Could you be looooved and be loooved\n"RST);
	else if (cmd == EXIT)
	{
		ft_exit(list, input, operator_tok, array, 1);
	}
}

void set_func(char *input, t_token *operator_tok, t_array array, t_list* list) 
{
	if (list == NULL)
		return ;
	else if (if_cmd(list->branch, "echo"))
	{
        list->comand = ECHO;
		list->cmd_text = str_cut(list->branch,"echo");//string po oříznutí příkazu echo
		printf(G"Priniting echo: %s\n"RST, list->cmd_text);
	}
    else if (if_cmd(list->branch, "cd"))
	{
        list->comand = CD;
		//list->cmd_text = str_cut(list->branch,"cd");
	}
    else if (if_cmd(list->branch, "pwd"))
        list->comand = PWD;
    else if (!(if_strwcmp(list->branch, "export")))
        list->comand = EXPORT;
    else if (!(if_strwcmp(list->branch, "unset")))
        list->comand = UNSET;
    else if (!(if_strwcmp(list->branch, "env")))
        list->comand = ENV;
    else if (!(if_strwcmp(list->branch, "exit")))
        list->comand = EXIT;
	s_cmd_handler(&list, input, operator_tok, array, list->comand);
}