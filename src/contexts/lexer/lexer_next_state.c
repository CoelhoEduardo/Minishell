/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_next_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:46:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 18:50:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	lexer_next_state(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;
	t_i8			character;

	character = lexer->cursor[lexer->index];
	if (character == '>')
		lexer->state = lexer->table[lexer->state][1];
	else if (character == '<')
		lexer->state = lexer->table[lexer->state][2];
	else if (character == '"')
		lexer->state = lexer->table[lexer->state][3];
	else if (character == '\'')
		lexer->state = lexer->table[lexer->state][4];
	else if (character == '|')
		lexer->state = lexer->table[lexer->state][5];
	else if (character == ' ' || (character >= '\t' && character <= '\r'))
		lexer->state = lexer->table[lexer->state][6];
	else if (character == '\0')
		lexer->state = lexer->table[lexer->state][7];
	else
		lexer->state = lexer->table[lexer->state][0];
}
