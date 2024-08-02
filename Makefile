# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:13:03 by pehenri2          #+#    #+#              #
#    Updated: 2024/08/02 18:50:50 by ecoelho-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minishell
CC					=	cc
CFLAGS				=	-Wextra -Wall -Werror -Wunreachable-code -g3
LIBFLAGS			=	-lreadline -lhistory 
HEADERS				= 	-I ./include -I $(LIBFT_PATH)/src
LIBFT				= 	$(addprefix $(LIBFT_PATH), libft.a)
LIBFT_PATH			= 	./lib/libft/
VPATH 				= 	./src:./src/builtin:./src/executor:./src/expansion:./src/lexer:./src/parser:./src/redirect:./src/signals:./src/utils
FILES				= 	main.c \
						builtins.c \
						cd.c \
						echo.c \
						env.c \
						exit.c \
						export_print.c \
						export.c \
						pwd.c \
						unset.c \
						execute_command.c \
						execute_pipe.c \
						execute_redirect.c \
						executor.c \
						expand_utils.c \
						expand.c \
						wildcard.c \
						lexer.c \
						open_syntax.c \
						bin_tree_helper.c \
						bin_tree.c \
						parser.c \
						heredoc.c \
						signals.c \
						environ.c \
						error.c \
						helper.c \
						line_prompt.c \
						token_list.c

OBJS				= 	$(FILES:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR				= 	obj

.DEFAULT_GOAL = $(NAME)

all: $(NAME) 

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBFT) $(LIBFLAGS) -o $(NAME)

bonus: $(OBJS) libft
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBFT) $(LIBFLAGS) -o minishell_bonus

libft:
	@make -C $(LIBFT_PATH) --silent

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<\n)"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean --silent
	@echo "Deleted object files"

fclean: clean
	@rm -rf $(NAME) minishell_bonus
	@make -C $(LIBFT_PATH) fclean --silent
	@echo "Deleted executable files and static libraries"

re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader

val: all
	valgrind --leak-check=full \
		--trace-children=yes \
		--show-leak-kinds=all \
		--suppressions=readline.supp \
		./$(NAME)
#		--track-fds=yes \
#       --track-origins=yes \
#       --log-file=valgrind-out.txt \

.PHONY: all, clean, fclean, re, norm, val
