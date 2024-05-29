/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:27:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/29 16:31:07 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_exit(t_token *cmd)
{
	long	status;

	status = 0;
	if (cmd->next)
	{
		status = ft_atol(cmd->next->value);
		if (validate_argument(cmd->next->value) == FAILURE
			|| check_limits(status) == FAILURE)
		{
			ft_fprintf(STDERR_FILENO, "exit\nexit:\
%s: numeric argument required\n", cmd->next->value);
			exit(SYNTAX_ERROR);
		}
		if (cmd->next->next)
		{
			write(STDERR_FILENO, "exit\nexit: too many arguments\n", 31);
			exit(EXIT_FAILURE);
		}
	}
	printf("exit\n");
	delete_heredoc_files();
	ft_free_memory();
	exit(status % 256);
	return (SUCCESS);
}

int	validate_argument(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_limits(long number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (FAILURE);
	return (SUCCESS);
}
