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


void quote_handle(char *str, t_list **list)
{
	if(if_quote(str, 39) || if_quote(str, 34))
	{
		if(!if_two_quote(str, 39) || !if_two_quote(str, 34))
			printf("print error");
		else
			qt_list_update(*list);
	}
}

