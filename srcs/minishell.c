#include "../include/minishell.h"

//we have to parse input into words and aperators and save it into right order
//then read parsed input
//read a line. 1st word == command; read till operator or white space
//after operator is new 1st word == command
//if wrong order/wrong syntax -> free list && save to log file
//proper cleanup

void	ft_init_return_input(t_list **list, t_array *array)
{
	char	*input;

//	input = (char*)ft_calloc(1024, sizeof(char));
	input = readline("minishell$ ");
	*list = NULL;
	add_history(input);
	*array = parse_input(input);
	free(input);
}

int	main(void)
{
	t_array	array;
	t_list	*list;
	t_token	*op_tok;
	// t_env	*env_var;

	// env_var = (t_env*)ft_calloc(1, sizeof(t_env));
	while (1)
	{
		ft_init_return_input(&list, &array);
		//op_tok = NULL;
		append_branch(array, &list);
		qt_list_update(list);

		//print_list(list);
	
		op_tok = tkn_find(list, array);
		op_tumbler(op_tok, array, list);
		set_func(op_tok, array, &list);
		// ft_free_all(&list, op_tok, array);
		free((list)->branch = NULL);
	}
		exit(1);
}