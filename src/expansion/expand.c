/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:07:20 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/29 18:10:11 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_command(t_tree_node *cmd_node)
{
	t_token	*current;

	current = cmd_node->cmd;
	while (current)
	{
		current->value = expand_vars(current->value);
		if (ft_strchr_quote_aware(current->value, '*'))
			expand_wildcards(&current, &cmd_node->cmd);
		if (ft_strchr_quote_aware(current->value, ' '))
			retokenize(&current);
		if (*(current->value) == '\0')
		{
			if (current->prev)
				current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
		}
		current->value = remove_quotes(current->value);
		current = current->next;
	}
	if (!*(cmd_node->cmd->value) && cmd_node->cmd->next)
	{
		cmd_node->cmd = cmd_node->cmd->next;
		cmd_node->cmd->prev = NULL;
	}
}

char	*expand_vars(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		
	}
}