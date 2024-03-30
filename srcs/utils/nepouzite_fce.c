/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nepouzite_fce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrojsa <jstrojsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:10:43 by jstrojsa          #+#    #+#             */
/*   Updated: 2024/03/30 20:47:32 by jstrojsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	msg_error(char *s)
{
	if (!DEBUG_MODE)
	{
		return ;
	}
	if (s == NULL)
	{
		return ;
	}
	write(2, "STDER:\t", 8);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	// write(2, "\nEND STDER\n", 12);
}

// void	*safe_malloc(size_t bytes)
// {
// 	void	*ret;

// 	ret = malloc(bytes);
// 	if (NULL == ret)
// 	{
// 		printf("Error: malloc failed");
// 		exit(1);
// 	}
// 	return (ret);
// }

// void	printf_return(char *messege)
// {
// 	printf("%s\n", messege);
// 	return ;
// }

// export ET=call_home
// echo $ET