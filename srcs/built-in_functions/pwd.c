#include "../include/minishell.h"

void  ft_pwd()
{
	char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
    return ;
}