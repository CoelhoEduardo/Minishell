/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_cut.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:48:13 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 21:46:33 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * See '2.10.1 Shell Grammar Lexical Conventions' 
*/
t_none	lexer_cut(t_mini mini)
{
	// const t_lexer	context = mini->lexer;
	// t_token					token;
	// t_u32					index;

	// if (context->delimiter_start > context->delimiter_end)
	// {
	// 	(context->cursor)++;
	// 	return ;
	// }
	// token = token_new(mini);
	// token->length = context->delimiter_end - context->delimiter_start + 1;
	// token->value = mini_alloc(mini, token->length + 1);
	// token->value[token->length] = '\0';
	// index = 0;
	// while (index < token->length)
	// {
	// 	token->value[index] = context->delimiter_start[index];
	// 	index++;
	// }
	// context->delimiter_start = context->delimiter_end + 1;
	// token->type = token_type_cstring(token->value);
	// linked_list_append(mini, context->tokens, token);
	(void)mini;
}
