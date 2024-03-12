#include "../../include/minishell.h"

//handle commands
void	cmd_handler(t_cmd cmd)
{
	if (cmd == INPUT_REDIR)
	{
		;
	}
	else if (cmd == OUTPUT_REDIR)
	{
		;
	}
	else if (cmd == INPUT_DELIM)
	{
		;
	}
	else if (cmd == OUTPUT_REDIR_A)
	{
		;
	}
	else if (cmd == PIPE)
	{
		;
	}
}

//handle standard commands
void	s_cmd_handler(t_cmd cmd)
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