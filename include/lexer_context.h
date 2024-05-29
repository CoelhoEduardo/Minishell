/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_context.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:57:23 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 21:24:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_CONTEXT_H
# define LEXER_CONTEXT_H

# include "minishell.h"

# define LEXER_MODE_ORDINARY 1
# define LEXER_MODE_HEREDOC 2

typedef struct s_lexer_context	*t_lexer_context;

struct s_lexer_context {
	t_cstring		line;
	t_cstring		buffer;
	t_linked_list	tokens;
};

t_lexer_context	lexer_context_new(t_mini mini);
t_none			lexer_context_reset(t_mini mini);

#endif