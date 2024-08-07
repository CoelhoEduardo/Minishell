/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:06:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/08/01 18:57:42 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_pipe(t_tree_node *left, t_tree_node *right)
{
	int	child_pid[2];
	int	pipe_fd[2];
	int	exit_status[2];

	pipe(pipe_fd);
	child_pid[0] = fork();
	setup_fork_signal_handlers(child_pid[0]);
	if (child_pid[0] == 0)
		execute_child(STDOUT_FILENO, pipe_fd, left);
	child_pid[1] = fork();
	setup_fork_signal_handlers(child_pid[1]);
	if (child_pid[1] == 0)
		execute_child(STDIN_FILENO, pipe_fd, right);
	close_pipe(pipe_fd);
	wait_child_status(child_pid[0], &exit_status[0]);
	wait_child_status(child_pid[1], &exit_status[1]);
	if (exit_status[0] == SIGINT + 128)
		return (exit_status[0]);
	return (exit_status[1]);
}

int	execute_child(int fd, int *pipe, t_tree_node *node)
{
	int	exit_status;

	dup2(pipe[fd], fd);
	close_pipe(pipe);
	exit_status = executor(node);
	ft_free_memory();
	free_env();
	exit(exit_status);
}

void	wait_child_status(pid_t pid, int *status)
{
	waitpid(pid, status, 0);
	if (WIFEXITED(*status))
		*status = WEXITSTATUS(*status);
	// Check for a specific exit status
	else if (*status == 1)
		return ;
	else if (WIFSIGNALED(*status))
	{
		if (*status == SIGINT)
			write(STDIN_FILENO, "\n", 1);
		*status = WTERMSIG(*status) + 128;
	}
}

// low-order 8 bits of the exit status value

