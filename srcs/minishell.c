#include "../include/minishell.h"

int	main(void)
{
	char	*input;
	t_list	list[5];
	t_parsed cmd_op;

	//we have to parse input into words and aperators and save it into right order
	//then read parsed input
		//read a line. 1st word == command; read till operator or white space
		//after operator is new 1st word == command
	//if wrong order/wrong syntax -> free list && save to log file
	while (1)
	{
		input = readline("minishell$ ");
		if (input) 
		{
			cmd_op = parse_input(input);
			printf("\n\nparsovani dokonceno\n");
			// create_list(list, input);
			printf("\n\n%d\n", print_size(list));
			append_branch(cmd_op, list);
			print_list(list);
			//append_node(list, );
			test_print(cmd_op);
			printf("\n\n%d\n", print_size(list));
			free(input); // Free the allocated memory
		}
	}
}