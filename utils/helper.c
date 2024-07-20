/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:44:45 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/20 17:46:40 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***get_my_env(void)
{
	static char	**env;

	return (&env);
}

int	*get_exit_status(void)
{
	static int	exit_status;

	return (&exit_status);
}

int	set_exit_status(int status)
{
	int	*exit_status;

	exit_status = get_exit_status();
	*exit_status = status;
	return (*exit_status);	
}

void	close_pipe(int *pipe_fd)
{
	if (pipe_fd[0] != -1)
		close(pipe_fd[0]);
	if (pipe_fd[1] != -1)
		close(pipe_fd[1]);
}
