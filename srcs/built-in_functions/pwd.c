#include "../../include/minishell.h"

void	ft_pwd()
{
	char	*cwd;

	cwd = getcwd(NULL, 1024);
	// cwd = (char*)safe_malloc(1024 * sizeof(char));
	// if (getcwd(cwd, sizeof(cwd)) != NULL)
	if (cwd != NULL)
		printf("%s\n", cwd);
	// printf("%s\n", cwd);
	free(cwd);
	return ;
}