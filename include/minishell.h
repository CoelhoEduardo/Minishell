/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:53:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 00:11:42 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "mini/primitives/i8.h"
# include "mini/primitives/u8.h"
# include "mini/primitives/i32.h"
# include "mini/primitives/u32.h"
# include "mini/primitives/i64.h"
# include "mini/primitives/u64.h"
# include "mini/primitives/any.h"
# include "mini/primitives/bool.h"
# include "mini/primitives/none.h"
# include "mini/primitives/memory.h"
# include "mini/primitives/cstring.h"
# include "mini/compounds/mini_list.h"
# include "mini/compounds/mini_tree.h"
# include "mini/systems/memtree.h"
# include "mini/systems/memstack.h"
# include "mini/processes/reader.h"
# include "mini/processes/lexer.h"
# include "mini/processes/expansion.h"
# include "mini/processes/parser.h"
# include "mini/processes/eval.h"
# include "mini/contexts/shared.h"

# define ENABLE_DEBUGGER
# ifdef ENABLE_DEBUGGER
#  include <stdio.h>
# endif

# define ENABLE_LUA
# ifdef ENABLE_LUA
#  include <lua5.4/lua.h>
#  include <lua5.4/lauxlib.h>
#  include <lua5.4/lualib.h>
# endif

# define PROMPT "mini> "
# define MULTILINE_PROMPT "> "

# define MEMORY_ALLOCATION_ERROR 1

typedef struct s_mini	*t_mini;

struct s_mini {
	t_shared	shared;
	t_reader	reader;
	t_lexer		lexer;
	t_expansion	expansion;
	t_parser	parser;
	t_eval		eval;
};

t_mini	mini_create(void);
t_mini	mini_assert(t_mini mini, t_bool condition, t_u8 code);
t_mini	mini_quit(t_mini mini, t_u8 code);

#endif