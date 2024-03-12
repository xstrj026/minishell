#include "../../include/minishell.h"

//handle commands
void	operator_handler(t_op operator)
{
	if (operator == INPUT_REDIR)
	{
		;
	}
	else if (operator == OUTPUT_REDIR)
	{
		;
	}
	else if (operator == INPUT_DELIM)
	{
		;
	}
	else if (operator == OUTPUT_REDIR_A)
	{
		;
	}
	else if (operator == PIPE)
	{
		;
	}
}

// cmd arg arg arg NULL | cmd arg arg

// echo |
// pwd > log.txt

//handle standard commands
void	s_cmd_handler(t_cmd cmd, char **args)
{
	if (cmd == ECHO_OPTION_N)
	{
		;
	}
	else if (cmd == CD_RELATIVE)
	{
		;
	}
	else if (cmd == CD_ABSOLUTE)
	{
		;
	}
	else if (cmd == PWD)
	{
		;
	}
	else if (cmd == EXPORT)
	{
		;
	}
	else if (cmd == UNSET)
	{
		;
	}
	else if (cmd == ENV)
	{
		;
	}
	else if (cmd == EXIT)
	{
		;
	}
}