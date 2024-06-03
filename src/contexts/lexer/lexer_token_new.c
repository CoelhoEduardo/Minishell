/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:28:32 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 17:09:12 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_token	lexer_token_new(t_mini mini)
{
	t_token	token;

	token = mini_alloc(mini, sizeof(struct s_token));
	token->length = 0;
	token->type = 0;
	token->value = NULL;
	return (token);
}
