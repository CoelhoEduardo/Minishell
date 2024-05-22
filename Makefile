# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 14:27:53 by bhildebr          #+#    #+#              #
#    Updated: 2024/05/22 14:27:53 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline

minishell_sources = 	src/main.c \
		src/cstring/cstring_copy.c \
		src/cstring/cstring_get_length.c \
		src/cstring/cstring_is_not_empty.c \
		src/cstring/cstring_join.c \
		src/cstring/cstring_to_stderr.c \
		src/cstring/cstring_to_stdout.c \
		src/memtree/memtree_create.c \
		src/memtree/memtree_destroy.c \
		src/memtree/memtree_get_height.c \
		src/memtree/memtree_insert.c \
		src/memtree/memtree_rebalance.c \
		src/memtree/memtree_remove.c \
		src/memtree/memtree_update_height.c \
		src/mini/mini_alloc.c \
		src/mini/mini_assert.c \
		src/mini/mini_check_flag.c \
		src/mini/mini_evaluate.c \
		src/mini/mini_free.c \
		src/mini/mini_get_cwd.c \
		src/mini/mini_get_prompt.c \
		src/mini/mini_get_transition_table.c \
		src/mini/mini_new.c \
		src/mini/mini_parse.c \
		src/mini/mini_quit.c \
		src/mini/mini_read.c \
		src/mini/mini_readline.c \
		src/mini/mini_tokenize.c

minishell_objects = 	src/main.o \
		src/cstring/cstring_copy.o \
		src/cstring/cstring_get_length.o \
		src/cstring/cstring_is_not_empty.o \
		src/cstring/cstring_join.o \
		src/cstring/cstring_to_stderr.o \
		src/cstring/cstring_to_stdout.o \
		src/memtree/memtree_create.o \
		src/memtree/memtree_destroy.o \
		src/memtree/memtree_get_height.o \
		src/memtree/memtree_insert.o \
		src/memtree/memtree_rebalance.o \
		src/memtree/memtree_remove.o \
		src/memtree/memtree_update_height.o \
		src/mini/mini_alloc.o \
		src/mini/mini_assert.o \
		src/mini/mini_check_flag.o \
		src/mini/mini_evaluate.o \
		src/mini/mini_free.o \
		src/mini/mini_get_cwd.o \
		src/mini/mini_get_prompt.o \
		src/mini/mini_get_transition_table.o \
		src/mini/mini_new.o \
		src/mini/mini_parse.o \
		src/mini/mini_quit.o \
		src/mini/mini_read.o \
		src/mini/mini_readline.o \
		src/mini/mini_tokenize.o

minishell_headers = 	include/any.h \
		include/assert.h \
		include/bool.h \
		include/btree.h \
		include/cstring.h \
		include/htable.h \
		include/i32.h \
		include/i64.h \
		include/i8.h \
		include/list.h \
		include/mem.h \
		include/memtree.h \
		include/minishell.h \
		include/none.h \
		include/token.h \
		include/tokenizer.h \
		include/u32.h

minishell_depends = 	src/main.d \
		src/cstring/cstring_copy.d \
		src/cstring/cstring_get_length.d \
		src/cstring/cstring_is_not_empty.d \
		src/cstring/cstring_join.d \
		src/cstring/cstring_to_stderr.d \
		src/cstring/cstring_to_stdout.d \
		src/memtree/memtree_create.d \
		src/memtree/memtree_destroy.d \
		src/memtree/memtree_get_height.d \
		src/memtree/memtree_insert.d \
		src/memtree/memtree_rebalance.d \
		src/memtree/memtree_remove.d \
		src/memtree/memtree_update_height.d \
		src/mini/mini_alloc.d \
		src/mini/mini_assert.d \
		src/mini/mini_check_flag.d \
		src/mini/mini_evaluate.d \
		src/mini/mini_free.d \
		src/mini/mini_get_cwd.d \
		src/mini/mini_get_prompt.d \
		src/mini/mini_get_transition_table.d \
		src/mini/mini_new.d \
		src/mini/mini_parse.d \
		src/mini/mini_quit.d \
		src/mini/mini_read.d \
		src/mini/mini_readline.d \
		src/mini/mini_tokenize.d

minishell_includes = 	-iquote include

all:
	@./script/generate_makefile > /dev/null 2>&1
	@$(MAKE) --no-print-directory $(NAME) 2>&1

$(NAME): $(minishell_objects)
	$(CC) $(CFLAGS) $(minishell_objects) $(minishell_includes) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(minishell_includes) -c $< -o $@

clean:
	$(RM) $(minishell_objects) $(minishell_depends)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm: 
	@norminette -R CheckForbiddenSourceHeader

val:
	valgrind --leak-check=full --trace-children=yes --show-leak-kinds=all --suppressions=readline.supp ./$(NAME)

run: all
	@./minishell

make:
	@./script/generate_makefile > /dev/null 2>&1

-include $(minishell_depends)

.PHONY: all clean fclean re norm val run make