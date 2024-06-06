/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:20:15 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 00:27:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

# define LEXER_MODE_ORDINARY 1
# define LEXER_MODE_HEREDOC 2

typedef struct s_lexer_process	*t_lexer_process;
typedef t_lexer_process			t_lexer;

struct s_lexer_process {
	t_i32			mode;
	t_mini_list		tokens;
	t_cstring		cursor;
	t_i32			start;
	t_i32			end;
	t_i32			state;
	t_i32			table[7][8];
};

t_none		mini_lexer_create(t_mini mini);

t_none		lexer_ordinary(t_mini mini);
t_none		lexer_heredoc(t_mini mini);
t_none		lexer_delimit(t_mini mini);

t_none		lexer_add_character(t_mini mini);
t_none		lexer_discard_character(t_mini mini);

t_none		lexer_next_state(t_mini mini);
t_bool		lexer_is_final_state(t_mini mini);

t_i32		lexer_classify(t_mini mini);
t_none		lexer_init_table(t_mini mini);

t_none		lexer_automaton(t_mini mini);
t_none		lexer_expand_word(t_mini mini, t_list_node node);

t_none		lexer_expand_dquotes(t_mini mini, t_list_node node);
t_cstring	lexer_expand(t_mini mini, t_cstring str);

#endif