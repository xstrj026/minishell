#include "../include/minishell.h"

int	main(void)
{
	char *input;

	while (1)
	{
		input = readline("minishell$ ");
		if (input) 
		{
			t_parsed cmdWords = parse_input(input);
			test_print(cmdWords);
			free(input); // Free the allocated memory
		}
	}
}