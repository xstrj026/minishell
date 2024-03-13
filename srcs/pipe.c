#include "../include/minishell.h"


int i_am_a_pipe(t_token *tkn, int i)
{
    int fd[2];
	if (pipe(fd) == -1)
	{
		printf("error ocured with opening");
		return 1;
	}
	int	id = fork();
	if (id == 0)
	{
        char *x = tkn[i].prev;
		close(fd[0]);
		write(fd[1], x, (ft_strlen(x)+1));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		char y[10];
		read(fd[0], y, (sizeof(y)));
		close(fd[0]);
		printf("our string is: %s\n", y);
	}
	return 0;
}

//pipe 
/*int	main(int argc, char*argv[])
{
    int fd[2];
	if (pipe(fd) == -1)
	{
		printf("error ocured with opening");
		return 1;
	}
	int	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		char x[10];
		printf("input a string: ");
		scanf("%s", x);
		write(fd[1], &x, (ft_strlen(x)));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		char y[10];
		read(fd[0], y, (sizeof(y)));
		close(fd[0]);
		printf("our string is: %s\n", y);
	}

	return	0;
}*/