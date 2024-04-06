#include "../include/minishell.h"

//we have to parse input into words and aperators and save it into right order
//then read parsed input
//read a line. 1st word == command; read till operator or white space
//after operator is new 1st word == command
//if wrong order/wrong syntax -> free list && save to log file
//proper cleanup

void	ft_init_return_input(t_list **list, t_array **main_array)
{
	char	*input;
	t_array	*array;

	msg_error("\t\tDEBUG MOD JE ZAPNUT");
	array = (*main_array);
	array->command_exist = false;
	array->operator_exist = false;

	input = readline("minishell$ ");
	printf("%s\n", input);
	*list = NULL;
	add_history(input);
	if (input == NULL)
		return ;
	array = parse_input(input, &array);
	free(input);
}

static void sigintHandler(int signum)
{
    // Signal handler function
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		signal(SIGINT, sigintHandler);
	}
}

void signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
        signal(SIGINT, signal_handler);
	}
}

int	main(void)
{
	t_array	*array;
	t_list	*list;
	t_token	*op_tok;
	t_env	*env_var;
	// int i = 0;

	// env_var = (t_env*)ft_calloc(1, sizeof(t_env));
	// array->cmd[i] = (char*)ft_calloc(1, sizeof(char*));
	// array->operator[i] = (char*)ft_calloc(1, sizeof(char*));
	env_var = NULL;
	array = (t_array*)ft_calloc(1, sizeof(t_array));
	signal(SIGINT, sigintHandler);
	while (1)
	{
		ft_init_return_input(&list, &array);
		//op_tok = NULL;
		if ((*array).command_exist == false && (*array).operator_exist == false)
			printf("command and operands does not exist\n");
		else
		{
			append_branch(array, &list);
			qt_list_update(list);
			//print_list(list);
			if ((*array).operator_exist)
			{
				op_tok = tkn_find(list, *array);
				op_tumbler(op_tok, *array, list);
			}
		}
		set_func(op_tok, &array, &list, &env_var);
		ft_free_all(&list, op_tok, &array);
		// free((list)->branch = NULL);
		// free(array);
		// if (list != NULL)
		// 	free(list);
	}
		exit(1);
	return (2);
}