/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:39:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 10:47:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "llist.h"
#include "binary_tree.h"
#include "token.h"

t_i32	parser(t_minishell mini)
{
	t_llist_node	current_node;
	t_token				current_token;
	t_token				next_token;

	current_node = mini->list->head;
	while (current_node)
	{
		current_token = (t_token)current_node->value;
		if (current_node->next)
		{
			next_token = ((t_token)current_node->next)->value;
		}
		else
		{
			next_token = NULL;
		}
		if (current_token->type == REDIR_HEREDOC && next_token && next_token->type == WORD)
			if (create_heredoc_file(current_node->next) != SUCCESS)
				return (get_exit_status(mini));
		if (check_syntax(current_node) != SUCCESS)
			return (set_exit_status(mini, SYNTAX_ERROR));
		current_node = current_node->next;
	}
	mini->tree = build_execution_tree(mini->list);
	return (SUCCESS);
}
