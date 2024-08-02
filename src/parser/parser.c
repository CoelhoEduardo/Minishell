/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:52:54 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/07/23 20:31:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(t_token *list, t_tree_node **root)
{
	t_token	*current;

	current = list;
	while (current)
	{
		if (check_syntax(current) != SUCCESS)
			return (set_exit_status(SYNTAX_ERROR));
		if (current->type == REDIR_HEREDOC && current->next->type == WORD)
			if (create_heredoc_file(current->next) != SUCCESS)
				return (*get_exit_status());
		current = current->next;
	}
	*root = build_execution_tree(list);
	return (SUCCESS);
}

int	check_syntax(t_token *current)
{
	if (current->type == AND || current->type == OR || current->type == PIPE)
		return (check_control_operator_rule(current));
	else if (current->type >= REDIR_APPEND && current->type <= REDIR_OUT)
		return (check_redirect_rule(current));
	else if (current->type == OPEN_PAREN || current->type == CLOSE_PAREN)
		return (check_parenthesis_rule(current));
	return (SUCCESS);
}

int	check_control_operator_rule(t_token *token)
{
	if (token->prev == NULL || token->prev->type <= PIPE
		|| token->prev->type == OPEN_PAREN)
		return (syntax_error(token->value));
	if (token->next == NULL || token->next->type <= PIPE
		|| token->next->type == CLOSE_PAREN)
		return (syntax_error(token->value));
	return (SUCCESS);
}

int	check_redirect_rule(t_token *token)
{
	if (token->next == NULL || token->next->type != WORD)
		return (syntax_error(token->value));
	return (SUCCESS);
}

int	check_parenthesis_rule(t_token *token)
{
	if (token->type == OPEN_PAREN)
	{
		/* O TOKEN ANTERIOR NAO PODE SER NADA ALEM DE AND, OR, PIPE, OPEN_PAREN */
		if (token->prev != NULL && token->prev->type > OPEN_PAREN)
			return (syntax_error(token->value));
		/* O PROXIMO TOKEN NAO PODE SER NULL OU PIPE, AND OU OR */
		if (token->next == NULL || token->next->type <= PIPE)
			return (syntax_error(token->value));
	}
	else if (token->type == CLOSE_PAREN)
	{
		/* O TOKEN ANTERIOR NAO PODE SER NULL E NEM NADA ALEM DE WORD OU CLOSE_PAREN */
		if (token->prev == NULL || (token->prev->type != WORD
				&& token->prev->type != CLOSE_PAREN))
			return (syntax_error(token->value));
		/* SE O PROXIMO TOKEN EXISTIR ELE NAO PODE SER UMA WORD */
		if (token->next != NULL && (token->next->type == WORD))
			return (syntax_error(token->value));
	}
	return (SUCCESS);
}
