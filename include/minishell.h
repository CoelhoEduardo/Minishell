/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:45:48 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/07/21 13:42:10 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <errno.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <wait.h>

# define SUCCESS 0
# define FAILURE 1
# define SYNTAX_ERROR 2

typedef struct s_token
{
	int					type;
	char				*value;
	struct s_token		*prev;
	struct s_token		*next;
}						t_token;

typedef struct s_tree_node
{
	t_token				*cmd;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}						t_tree_node;

enum					e_token_type
{
	AND = 1,
	OR,
	PIPE,
	OPEN_PAREN,
	CLOSE_PAREN,
	REDIR_APPEND,
	REDIR_HEREDOC,
	REDIR_IN,
	REDIR_OUT,
	SPACES,
	END,
	WORD,
};

/* EXPANSION */

void					expand_tokens(t_tree_node *cmd_node);
char					*expand_vars(char *str);
char					*handle_dollar(char *start, char **str);
char					*handle_special_cases(char *dollar, char **str,
							char **after_var, char **expanded_var);

char					*remove_quotes(char *str);
void					retokenize(t_token **token);
void					handle_empty_value(t_token **current,
							t_tree_node **cmd_node);

void					expand_wildcards(t_token **token, t_tree_node **node);
bool					is_match(char *text, char *pattern);
bool					**init_lookup_table(char *text, int *text_length,
							char *pattern, int *pattern_length);
bool					match_result_and_free(bool **lookup, int text_length,
							int pattern_length);
void					update_token_list(t_token **token, t_token *matched);

/*LEXER*/

int						lexer(char *str, t_token **list);
int						get_token_type(char *str);
int						get_token_length(char *str, int type);
int						get_word_length(char *str);

int						check_open_syntax(char *str);
void					move_to_next_quote(char *str, int *index,
							int *single_quote, int *double_quote);

/* BIN_TREE */

t_tree_node				*build_execution_tree(t_token *token_list);
void					split_tokens_into_tree(t_tree_node *tree_node,
							t_token *token_list);
void					split_list(t_tree_node *tree_node, t_token *token_list,
							t_token *token_to_cut);
t_token					*cut_token_list(t_token *token_list,
							t_token *token_to_cut);
void					split_redirect(t_tree_node *tree_node,
							t_token *token_list, t_token *token_to_cut);

t_token					*search_and_or(t_token *token_list);
t_token					*search_pipe(t_token *token_list);
t_token					*search_redirect(t_token *token_list);
t_tree_node				*get_redir_filename(t_token *redir);

/* PARSER */
int						parser(t_token *list, t_tree_node **root);
int						check_syntax(t_token *current);
int						check_control_operator_rule(t_token *token);
int						check_redirect_rule(t_token *token);
int						check_parenthesis_rule(t_token *token);

/* HEREDOC */
int						create_heredoc_file(t_token *token);
int						write_input_to_heredoc(int fd, char *end_condition,
							int is_expandable);
int						delete_heredoc_files(void);
int						*get_heredoc_counter(void);

#endif