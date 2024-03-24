#include "../../include/minishell.h"

int if_two_quote(char *str, char c)
{
	int i;
	int qt;

	i = 0;
	qt = 0;
	while(str[i])
	{
		if(str[i] == c)
			qt++;
		i++;
	}
	if((qt % 2) == 0)
		return(1);
	return(0);
}

int if_quote(char *str, char c)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return(1);
		i++;
	}
	return(0);
}


int quote_handle(char *str)
{
	if(!if_two_quote(str, 39) || !if_two_quote(str, 34))
		{
			printf("print error\n");
			return (1);
		}
	return(0);
}

int one_case(char *str)
{
	int i;

	i = 0;
	if(str[i] && str[i+1] == '\0')
		{
			ft_putchar_fd(str[i], 1);
			return(1);
		}
	return(0);
}