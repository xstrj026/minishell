/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_dollar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:35:28 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/03/30 21:04:18 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	info_debug_msg(int wc)
{
	char	*count;

	count = ft_itoa(wc);
	msg_error("pocet $ je");
	msg_error(count);
	free(count);
	return (wc);
}

//counts words
int	sign_count(char *str, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] != c))
			i++;
		if (str[i] == c)
			wc++;
		while (str[i] && (str[i] == c || (str[i] >= 'A' && str[i] <= 'Z')
				|| str[i] == '_' || (str[i] >= 'a' && str[i] <= 'z')))
			i++;
		if (str[i] != '\0')
			break ;
	}
	return (info_debug_msg(wc));
}

void	print_array_char(char **str)
{
	int	i;

	i = 0;
	msg_error("array of $env:");
	while (str[i] != NULL)
	{
		msg_error(str[i]);
		i++;
	}
	return ;
}

//parsovani na slova
char	**ft_env(char *str)
{
	int		i;
	int		j = 0;
	int		k = 0;
	int		wc;
	char	**out;

	wc = sign_count(str, '$');//pocet promennych
	out = (char **)ft_calloc((wc + 1), sizeof(char *));//alokace pameti pro ne vcetne NULL
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
			out[k] = (char *)ft_calloc(((i - j) + 1), sizeof(char));
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

char	*ft_key_value(char *variable_name, t_env *env)
{
	int	i;

	variable_name++;
	i = 0;
	msg_error("jsem v ft_key");
	while (env[i].key)
	{
		if (ft_strcmp(env[i].key, variable_name) == 0)
		{
			if (DEBUG_MODE)
			{
				msg_error("hodnota funkce ft_key_value: ");
				msg_error(env[i].value);
			}
			return (env[i].value);
		}
		i++;
	}
	return (0);
}

//pokud dolar, pouzije se var
void	print_if_dollar_or_word(char *str, t_env *env, char **array_q)
{
	char	*var;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			var = ft_key_value(array_q[j], env);
			while (str[i] && (str[i] == '$' ||
					(str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_'))
				i++;
			ft_putstr_fd(var, 1);
		}
		if (str[i] != '"')
			ft_putchar_fd(str[i], 1);
		if (str[i] == '\0')
			break ;
		i++;
	}
}



void	handle_dollar(char *str, t_env **m_env)
{
	t_env	*env;
	char	**array_q;

	env = *m_env;
	array_q = ft_env(str);
	if (DEBUG_MODE)
		print_array_char(array_q);
	print_if_dollar_or_word(str, env, array_q);
	int m = 0;
	while (array_q[m])
	{
		free(array_q[m]);
		m++;
	}
	free(array_q);
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
