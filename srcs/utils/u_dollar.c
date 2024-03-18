#include "../../include/minishell.h"

char	**ft_env(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	while (str[i])
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
/*
void handle_dollar(char *str)
{
	int i = 0;
	int j = -1;
	int if_dollar;
	char *var;

	t_env env[] = 
	{
		{.key = "HOME", .value = "/home"},
		{.key = "USR", .value = "yuma"},
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
		if_dollar = 0;
		if (str[i] == '$')
			if_dollar = 1;
		if(if_dollar)
		{
			var = ft_key_value(array_q[++j], env);
			while(str[i] && str[i] != ' ')
				i++;
			ft_putstr_fd(var, 1);
		}
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

void handle_quote(char *str)
{
	int i = 0;
	int j = -1;
	int dlr;
	int if_sgl_qt;
	int if_sgl_qt_i;
	int dbl_qt;
	char *var;

	t_env env[] = 
	{
		{.key = "$HOME", .value = "/home"},
		{.key = "$USR", .value = "Yuma"},
		{.key = "$CAT_HOME", .value = "Mika"},
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
	if_sgl_qt = 0;
	dbl_qt = 0;
	if_sgl_qt_i = 0;
	while(str[i])
	{
		dlr = 0;
		if (str[i] == 39)
		{
			if_sgl_qt = 1;
			if_sgl_qt_i++;
			i++;
		}
		if (if_sgl_qt_i)
		{
			if((if_sgl_qt_i % 2) == 0)
				if_sgl_qt = 0;		
		}	
		if (str[i] == '$' && !if_sgl_qt)
			dlr = 1;
		if(dlr)
		{
			var = ft_key_value(array_q[++j], env);
			while (str[i] && (str[i] == '$' || (str[i] >= 'A' && str[i] <= 'Z') ||str[i] == '_' ))
				i++;
			ft_putstr_fd(var, 1);
		}
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
}*/

void handle_echo_quote(char *str)
{
	int i = 0;
	int j = -1;
	int dlr;
	int if_sgl_qt;
	int if_sgl_qt_i;
	int if_dbl_qt;
	int if_dbl_qt_i;
	int if_sgl_dlr;
	char *var;

	t_env env[] = 
	{
		{.key = "$HOME", .value = "/home"},
		{.key = "$USR", .value = "Yuma"},
		{.key = "$CAT_HOME", .value = "Mika"},
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
	if_sgl_qt = 0;
	if_dbl_qt = 0;
	if_sgl_qt_i = 0;
	if_dbl_qt_i = 0;
	if_sgl_dlr = 0;
	while(str[i] != '\0')
	{
		dlr = 0;
		if (str[i] == 39)
		{
			if_sgl_qt = 1;
			if_sgl_qt_i++;
		}
		else if (str[i] == 34)
		{
			if_dbl_qt = 1;
			if_dbl_qt_i++;
		}
		if (if_sgl_qt_i)
		{
			if((if_sgl_qt_i % 2) == 0)
				if_sgl_qt = 0;
			while(str[i] == 39)
				i++;	
		}
		else if (if_dbl_qt_i)
		{
			if((if_dbl_qt_i % 2) == 0)
				if_dbl_qt = 0;
			while(str[i] == 34)
				i++;
		}
		if (str[i] == '$' && if_sgl_qt)
			if_sgl_dlr++;
		else if ((str[i] == '$' && !if_sgl_qt && if_dbl_qt) || (str[i] == '$' && !if_sgl_qt))
			dlr = 1;
		if(dlr)
		{
			var = ft_key_value(array_q[++j + if_sgl_dlr], env);
			while (str[i] && (str[i] == '$' || (str[i] >= 'A' && str[i] <= 'Z') ||str[i] == '_' ))
				i++;
			if(str[i] == 34)
				i++;
			ft_putstr_fd(var, 1);
		}
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

void i_am_testing_quotes()
{
    // Test Case: Simple strings
    handle_echo_quote("hello world\n");
	printf("1.Expected: hello world\n");

    handle_echo_quote("\"hello world\"\n");
	printf("2.Expected: hello world\n");

    handle_echo_quote("'hello world'\n");
	printf("3.Expected: hello world\n");

    handle_echo_quote("hello'world'\n");
	printf("4.Expected: helloworld\n");

    handle_echo_quote("hello\"\"world\n");
	printf("5.Expected: helloworld\n");
    handle_echo_quote("''\n");
    printf("6.Expected: \n");

	// Test Case: Environment variable
    handle_echo_quote("\"$CAT_HOME\"\n");
    handle_echo_quote("'$CAT_HOME'\n");
}