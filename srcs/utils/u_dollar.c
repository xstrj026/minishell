#include "../../include/minishell.h"

char	**ft_env(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] != '$'))
			i++;
		if (str[i] == '$')
			wc++;
		while (str[i] && (str[i] == '$' || (str[i] >= 'A' && str[i] <= 'Z') ||str[i] == '_' )) {
    i++;
}
	}
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] != '$')) 
			i++;
		j = i;
		while (str[i] && (str[i] == '$' || (str[i] >= 'A' && str[i] <= 'Z') ||str[i] == '_' ))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}


void d_test_print(char *str) 
{
	char **array_z;
	array_z = ft_env(str);
    if (DEBUG_MODE)
    {
        printf(G"Here we are testing operators in array:\n"RST);
        for (int i = 0; array_z[i] != NULL; i++) 
        {
            printf("%d:%s\n", i, array_z[i]);
        }
    }
}

char *ft_key_value(char *str, t_env *env)
{
	int i;

	i = 0;
	while(env[i].key)
	{
		if(!ft_strcmp(env[i].key, str))
			return(env[i].value);
		i++;
	}
	return(0);
}


void handle_dollar(char *str)
{
	int i = 0;
	int j = -1;
	int dlr = 0;
	char *var;

	t_env env[] = 
	{
		{.key = "$HOME", .value = "/home"},
		{.key = "$USR", .value = "yuma"},
	};
    char **array_q;
	array_q = ft_env(str);
	if (DEBUG_MODE)
    {
        for (int g = 0; array_q[g] != NULL; g++) 
        {
            printf("%d:%s\n", g, array_q[g]);
        }
    }
	while(str[i])
	{
		dlr = 0;
		if (str[i] == '$')
			dlr = 1;
		if(dlr)
		{
			var = ft_key_value(array_q[++j], env);
			while (str[i] && (str[i] == '$' || (str[i] >= 'A' && str[i] <= 'Z') ||str[i] == '_'))
				i++;
			ft_putstr_fd(var, 1);
		}
		if(str[i] != 34)
			ft_putchar_fd(str[i], 1);
		i++;
	}
	free(array_q);
	int m = 0;
	while (array_q[m])
	{
		free(array_q[m]);
		m++;
	}
}

void skip_quotes(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] != 39)
			ft_putchar_fd(str[i], 1);
		i++;
	}
}
