/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:09:20 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 09:38:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <stdarg.h>
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
	int				type;
	char			*value;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_tree_node
{
	t_token				*cmd;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}	t_tree_node;

enum e_token_type {
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

/*******************************************
############## BUILTIN FOLDER ##############
*******************************************/

/*************** builtins.c ***************/

bool		is_builtin(t_token *cmd);
int			execute_builtin(t_token *cmd);

/****************** cd.c ******************/

int			execute_cd(t_token *cmd);
int			change_to_home(void);
int			change_dir(char *path);
int			check_access(char *path);

/***************** echo.c *****************/

int			execute_echo(t_token *cmd);
int			check_n_flag(char *str);
void		print_args(char **args, int has_n_flag);

/***************** env.c ******************/

int			execute_env(t_token *cmd);

/***************** exit.c *****************/

int			execute_exit(t_token *cmd);
int			validate_argument(char *arg);
int			check_limits(long number);

/***************** export.c ******************/

int			execute_export(t_token *cmd);
char		*get_key(char *arg);
int			is_valid_identifier(char *str);
int			is_env_key_present(char *key);
int			is_key_without_value(char *key);

/***************** export_print.c ******************/

void		print_environ_sorted(void);
int			print_smallest_unprinted(
				char **env,
				size_t env_size,
				char *printed);
void		format_and_print(const char *env_var);

/***************** pwd.c ******************/

int			execute_pwd(void);

/***************** unset.c ******************/

int			execute_unset(t_token *cmd);
void		delete_env_key(char *key_to_delete);

/*******************************************
############# EXECUTOR FOLDER ##############
*******************************************/

/************ execute_command.c ***********/

int			execute_command(t_tree_node *cmd_node);
void		run_command_in_child_process(t_token *cmd);
char		*get_cmd_path(t_token *cmd);
char		*search_in_path(t_token *cmd);
char		**get_cmd_and_args(t_token *cmd);

/************* execute_pipe.c *************/

int			execute_pipe(t_tree_node *left, t_tree_node *right);
int			execute_child(int fd, int *pipe, t_tree_node *node);

/*********** execute_redirect.c ***********/

int			execute_redirect(
				t_tree_node *left,
				t_tree_node *right,
				int redir_type);
int			open_redir_file(
				t_tree_node *right,
				int redir_type,
				int *fd);
int			dup2_redir_file(int redir_type, int *fd);

/*************** executor.c ***************/

int			executor(t_tree_node *root);
int			execute_and(t_tree_node *left, t_tree_node *right);
int			execute_or(t_tree_node *left, t_tree_node *right);
int			execute_block(t_tree_node *root);

/*******************************************
############# EXPANSION FOLDER #############
*******************************************/

/**************** expand.c ****************/

void		expand_command(t_tree_node *cmd_node);
char		*expand_vars(char *str);
char		*handle_dollar(char *start, char **str);
char		*remove_quotes(char *str);
void		retokenize(t_token **token);

/************* wildcard.c ****************/

void		expand_wildcards(t_token **token, t_token **cmd);
bool		is_match(char *text, char *pattern);
bool		**init_lookup_table(
				char *text,
				int *text_length,
				char *pattern,
				int *pattern_length);
bool		match_result_and_free(
				bool **lookup,
				int text_length,
				int pattern_length);
void		update_token_list(t_token **token, t_token *matched);

/*******************************************
############### LEXER FOLDER ###############
*******************************************/

/**************** lexer.c *****************/

int			lexer(char *str, t_token **list);
int			get_token_type(char *str);
int			get_token_length(char *str, int type);
int			get_word_length(char *str);

/************* open_syntax.c **************/

int			check_open_syntax(char *str);
void		move_to_next_quote(
				char *str,
				int *index,
				int *single_quote,
				int *double_quote);

/*******************************************
############### LIBFT FOLDER ###############
*******************************************/

# define NULL_BYTE 1
# define ERROR_CODE -1
# define FD_LIMIT 1024
# define S_QUOTE '\''
# define D_QUOTE '\"'
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_dlst
{
	void			*content;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}					t_dlst;

int					ft_isalpha(int point);
int					ft_isdigit(int point);
int					ft_isalnum(int point);
int					ft_isascii(int point);
int					ft_isprint(int point);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int point, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int point);
int					ft_tolower(int point);
char				*ft_strchr(const char *s, int point);
char				*ft_strrchr(const char *s, int point);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int point, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char point);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
int					ft_putendl_fd(char *s, int fd);
int					ft_putnbr_fd(long n, int fd);
int					ft_putptr_fd(unsigned long nbr, int fd);
int					ft_putnbr_base_fd(long nbr, char *base, int fd);

char				*get_next_line(int fd);
int					ft_wordcount(char *str, char delimiter);
void				ft_freepp(char **arr);
unsigned int		ft_atoi_base(char *str, int str_base);
float				ft_absolute(float a);
float				ft_maxval(float a, float b);
void				ft_print_words(char **str);
long				ft_atol(char *str);
int					ft_isspace(char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_arrstr_len(char **str);
int					ft_fprintf(int fd, const char *format, ...);
char				*ft_strndup(char *s, int n);
char				*ft_strdup_calloc(const char *s);
char				*ft_strchr_quote_aware(const char *s, int c);

// SPLIT_QUOTE
void				ft_add_word(char *str, char delimiter, char *dst);
int					ft_countwords_quote(char *str, char delimiter);
int					ft_get_len(char *str, char delimiter);
char				*ft_move_next_word(char *str, char delimiter);
char				**ft_quote_split(char *str, char delimiter);

// list utils
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstadd_back_arr(t_list **lst, void **content);

// double linked list utils
void				ft_dlst_add_back(t_dlst *list, t_dlst *new);
void				ft_dlst_add_front(t_dlst *list, t_dlst *new);
t_dlst				*ft_dlst_last(t_dlst *list);
t_dlst				*ft_dlst_new(void *content);
int					ft_dlst_size(t_dlst *list);

// memory collector
t_list				**ft_get_memory_lst(void);
void				ft_collect_mem(void *content);
void				ft_collect_mem_arr(void **content);
void				ft_free_memory(void);
void				*ft_dalloc(size_t nmemb, size_t size);

# ifndef FT_PRINTF_H
#  define FT_PRINTF_H

typedef struct s_format
{
	va_list			ap;
	int				wdt;
	int				prc;
	int				zero;
	int				pnt;
	int				dash;
	int				tl;
	int				sign;
	int				is_zero;
	int				perc;
	int				sp;
	int				hash;
	int				lowc;
	int				upc;
}					t_format;

// utils
t_format			*inicialize_flags(t_format *flags);
int					ft_printf(const char *format, ...);

// ft_eval_format
int					is_normal_flag(char c);
int					ft_eval_format(t_format *flags, const char *format, int i);
int					ft_print_format(char c, t_format *flags);

// normal flags
int					ft_print_char(t_format *flag);
int					ft_print_str(t_format *flags);
int					ft_print_digit(t_format *flags);
int					ft_print_ex(t_format *flags);
int					ft_print_ex_up(t_format *flags);
int					ft_print_pointer(t_format *flags);
int					ft_print_unsigned(t_format *flags);
# endif

/*******************************************
############## PARSER FOLDER ###############
*******************************************/

/*************** bin_tree.c ***************/

t_tree_node	*build_execution_tree(t_token *token_list);
void		split_tokens_into_tree(
				t_tree_node *tree_node,
				t_token *token_list);
void		split_list(
				t_tree_node *tree_node,
				t_token *token_list,
				t_token *token_to_cut);
t_token		*cut_token_list(
				t_token *token_list,
				t_token	*token_to_cut);
void		split_redirect(
				t_tree_node *tree_node,
				t_token *token_list,
				t_token *token_to_cut);

/*********** bin_tree_helper.c ************/

t_token		*search_and_or(t_token *token_list);
t_token		*search_pipe(t_token *token_list);
t_token		*search_redirect(t_token *token_list);
t_token		*get_redir_filename(t_token *redir);

/**************** parser.c ****************/

int			parser(t_token *list, t_tree_node **root);
int			check_syntax(t_token *current);
int			check_control_operator_rule(t_token *token);
int			check_redirect_rule(t_token *token);
int			check_parenthesis_rule(t_token *token);

/*******************************************
############# REDIRECT FOLDER ##############
*******************************************/

/*************** heredoc.c ****************/

int			create_heredoc_file(t_token *token);
int			write_input_to_heredoc(
				int fd,
				char *end_condition,
				int is_expandable);
int			delete_heredoc_files(void);
int			*get_heredoc_counter(void);

/*******************************************
############## SIGNALS FOLDER ##############
*******************************************/

/*************** signals.c ****************/
int			setup_signal_handler(void (*func)(int signum));
int			setup_fork_signal_handlers(int pid);
void		main_signal_handler(int signum);
void		heredoc_signal_handler(int signum);

/*******************************************
############### UTILS FOLDER ###############
*******************************************/

/**************** error.c *****************/

int			syntax_error(char *token);
int			throw_error(char *cmd_path);
int			handle_error(char *message);
int			signal_error(void);

/**************** helper.c ****************/

int			*get_exit_status(void);
int			set_exit_status(int status);
void		wait_child_status(pid_t pid, int *status);
void		reset_for_next_iteration(char *line);
void		close_pipe(int *pipe_fd);

/************** token_list.c **************/

t_token		*token_lst_new(char *value, int type);
void		token_lst_add_back(t_token **token_list, t_token *new);
int			token_lst_get_size(t_token *token_list);
t_token		*token_lst_get_last(t_token *token_list);
void		sort_token_lst(t_token **matched);

/**************** environ.c ****************/

void		init_environ(void);
void		free_env(void);
void		set_env(char *new_str, char *key, char *content);
void		add_to_env(char *str);
void		update_env(char *new_str, char *key);

#endif