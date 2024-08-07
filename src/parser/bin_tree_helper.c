/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_tree_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:15:08 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/07/26 20:29:36 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*search_and_or(t_token *token_list)
{
	t_token	*current;
	int		parentesis;

	current = token_lst_get_last(token_list);
	while (current)
	{
		if (current->type == AND || current->type == OR)
			return (current);
		if (current->type == CLOSE_PAREN)
		{
			parentesis = 1;
			while (parentesis)
			{
				current = current->prev;
				if (current->type == CLOSE_PAREN)
					parentesis++;
				else if (current->type == OPEN_PAREN)
					parentesis--;
			}
		}
		current = current->prev;
	}
	return (NULL);
}

t_token	*search_pipe(t_token *token_list)
{
	t_token	*current;
	int		parentesis;

	current = token_lst_get_last(token_list);
	while (current)
	{
		if (current->type == PIPE)
			return (current);
		if (current->type == CLOSE_PAREN)
		{
			parentesis = 1;
			while (parentesis)
			{
				current = current->prev;
				if (current->type == CLOSE_PAREN)
					parentesis++;
				else if (current->type == OPEN_PAREN)
					parentesis--;
			}
		}
		current = current->prev;
	}
	return (NULL);
}



t_token	*search_redirect(t_token *token_list)
{
	t_token	*current;
	int		parentesis;

	current = token_list;
	while (current)
	{
		if (current->type >= REDIR_APPEND && current->type <= REDIR_OUT)
			return (current);
		if (current->type == OPEN_PAREN)
		{
			parentesis = 1;
			while (parentesis)
			{
				current = current->next;
				if (current->type == OPEN_PAREN)
					parentesis++;
				else if (current->type == CLOSE_PAREN)
					parentesis--;
			}
		}
		current = current->next;
	}
	return (NULL);
}

t_tree_node	*get_redir_filename(t_token *redir)
{
	t_tree_node	*filename;

	filename = ft_dalloc(1, sizeof(t_tree_node));
	if (!filename)
	{
		perror("failed to build execution tree");
		return (NULL);
	}
	else
	{
		filename->cmd = redir;
		filename->cmd->prev = NULL;
		filename->left = NULL;
		filename->right = NULL;
	}
	return (filename);
}
