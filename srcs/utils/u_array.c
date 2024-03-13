#include "../../include/minishell.h"

void test_print(t_parsed cmdWords) {
    printf(G"Here we are testing operators in array:\n"RST);
    for (int i = 0; cmdWords.operator[i] != NULL; i++) {
        printf("%d: %s\n", i, cmdWords.operator[i]);
    }

    printf(G"Here we are testing commands in array:\n"RST);
    for (int i = 0; cmdWords.cmd[i] != NULL; i++) {
        printf("%d: %s\n", i, cmdWords.cmd[i]);
    }
}

int op_size(t_parsed cmdWords) 
{
	int i;

	i = 0;
    while (cmdWords.operator[i] != NULL) 
	{
		i++;
    }
	return(i);
}
