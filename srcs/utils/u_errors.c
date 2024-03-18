#include "../../include/minishell.h"

void	print_errors(t_error error)
{
	if (error == ERROR_MALLOC)
	{
		printf(RED"Oooops! Error occured!\n"RST);
		
	}
	else if (error == TOKEN_UNEXP)
		printf(RED"Oooops! Error occured!\n"RST);
}

void	print_sign(t_sign sign)
{
	if (sign == STAND_SIGN)
	{
		printf("Hello! I am mini shell and I am waiting for your command to process."
			"\n My PID IS: %d\n", getpid());
	}
}