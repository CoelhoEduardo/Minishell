/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:11:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/16 20:33:40 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_parse(t_mini mini)
{
	mini_parser_reset(mini);
	if (mini_parser_get_token(mini) == END)
		mini->parser->tree = NULL;
	else
	{
		mini->parser->tree = mini_parse_pipe_sequence(mini);
		if (mini->parser->tree)
		{
			if (mini->parser->found_heredoc)
			{
				if (mini->shared->is_statement_complete == TRUE)
					mini->shared->is_heredoc_complete = FALSE;
			}
		}
		else if (mini->parser->could_be_completed)
			mini->shared->is_statement_complete = FALSE;
		else
		{
			mini_parser_print_syntax_error(mini);
			mini_reset(mini);
		}
	}
	printf("\033[94m[%s:%d]\n(command)\033[0m ", __func__, __LINE__);
	mini_pipe_tree_print(mini, mini->parser->tree);
}
