/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:30:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/20 17:55:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_echo(t_token *cmd)
{
	char	**args;
	int		has_n_flag;

	has_n_flag = 0;
	args = get_cmd_and_args(cmd);
	args++;
	while (*args && check_n_flag(*args))
	{
		has_n_flag = 1;
		args++;
	}
	print_args(args, has_n_flag);
	return (SUCCESS);
}

int	check_n_flag(char *str)
{
	if (*str == '-' && *(str + 1) == 'n')
	{
		str++;
		while (*str == 'n')
			str++;
		if (*str == '\0')
			return (1);
	}
	return (0);
}

void	print_args(char **args, int has_n_flag)
{
	while (*args)
	{
		ft_putstr_fd(*args, STDOUT_FILENO);
		if (*(args + 1))
			ft_putchar_fd(' ', STDOUT_FILENO);
		args++;
	}
	if (!has_n_flag)
		ft_putchar_fd('\n', STDOUT_FILENO);
}
