#include "../../include/minishell.h"

void test_print(t_array array) 
{
    if (DEBUG_MODE)
    {
        printf(G"Here we are testing operators in array:\n"RST);
        for (int i = 0; array.operator[i] != NULL; i++) 
        {
            printf("%d:%s\n", i, array.operator[i]);
        }
        printf(G"Here we are testing commands in array:\n"RST);
        for (int i = 0; array.cmd[i] != NULL; i++) 
        {
            printf("%d:%s\n", i, array.cmd[i]);
        }
    }
}

int op_size(t_array array) 
{
	int i;

	i = 0;
    while (array.operator[i] != NULL) 
	{
		i++;
    }
	return(i);
}
