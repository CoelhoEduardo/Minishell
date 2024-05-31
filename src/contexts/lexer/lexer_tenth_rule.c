/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_tenth_rule.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:15:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 20:07:10 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 10th rule:
 * The current character is used as the start of a new word.
*/
t_none	mini_lexer_tenth_rule(t_mini mini)
{
	// const t_lexer	context = mini->lexer;

	// if (context->has_applied_rule)
	// 	return ;
	// context->delimiter_start = context->cursor;
	// context->is_word = TRUE;
	// (context->cursor)++;
	(void)mini;
}
