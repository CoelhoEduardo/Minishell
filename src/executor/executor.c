/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:19:25 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/26 21:44:4:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executor(t_tree_node *root)
{
	if (!root->cmd)
		return (SUCCESS);
	if (root->cmd->type == AND)
		return (execute_and(root->left, root->right));
	else if (root->cmd->type == OR)
		return (execute_or(root->left, root->right));
	else if (root->cmd->type == PIPE)
		return (execute_pipe(root->left, root->right));
	else if (root->cmd->type >= REDIR_APPEND && root->cmd->type <= REDIR_OUT)
		return (execute_redirect(root->left, root->right, root->cmd->type));
	else if (root->cmd->type == OPEN_PAREN)
		return (execute_block(root));
	else
		return (execute_command(root));
}

int	execute_and(t_tree_node *left, t_tree_node *right)
{
	int	exit_status;

	exit_status = set_exit_status(executor(left));
	if (exit_status == SUCCESS)
		return (set_exit_status(executor(right)));
	return (exit_status);
}

int	execute_or(t_tree_node *left, t_tree_node *right)
{
	int	exit_status;

	exit_status = set_exit_status(executor(left));
	if (exit_status != SUCCESS && *get_exit_status() < 128)
		return (set_exit_status(executor(right)));
	return (exit_status);
}

int	execute_block(t_tree_node *root)
{
	t_tree_node	*block_root;
	t_token		*current;
	int			exit_status;
	int			pid;

	pid = fork();
	if (pid == -1)
		exit(handle_error("fork"));
	if (pid == 0)
	{
		root->cmd = root->cmd->next;
		current = root->cmd;
		while (current->next)
			current = current->next;
		current->prev->next = NULL;
		if (parser(root->cmd, &block_root) == SUCCESS)
			exit(executor(block_root));
	}
	wait_child_status(pid, &exit_status);
	return (exit_status);
}
