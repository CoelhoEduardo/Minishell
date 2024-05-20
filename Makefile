# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 19:58:59 by bhildebr          #+#    #+#              #
#    Updated: 2024/05/20 19:58:59 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline

minishell_sources = 	src/main.c \
		src/cstring/cstring_copy.c \
		src/cstring/cstring_get_length.c \
		src/cstring/cstring_join.c \
		src/cstring/cstring_to_stderr.c \
		src/memtree/memtree_create.c \
		src/memtree/memtree_destroy.c \
		src/memtree/memtree_get_height.c \
		src/memtree/memtree_insert.c \
		src/memtree/memtree_rebalance.c \
		src/memtree/memtree_remove.c \
		src/memtree/memtree_update_height.c \
		src/mini/mini_alloc.c \
		src/mini/mini_assert.c \
		src/mini/mini_evaluate.c \
		src/mini/mini_free.c \
		src/mini/mini_get_prompt.c \
		src/mini/mini_new.c \
		src/mini/mini_print.c \
		src/mini/mini_quit.c \
		src/mini/mini_read.c \
		src/tokenizer/tokenize.c

minishell_objects = 	src/main.o \
		src/cstring/cstring_copy.o \
		src/cstring/cstring_get_length.o \
		src/cstring/cstring_join.o \
		src/cstring/cstring_to_stderr.o \
		src/memtree/memtree_create.o \
		src/memtree/memtree_destroy.o \
		src/memtree/memtree_get_height.o \
		src/memtree/memtree_insert.o \
		src/memtree/memtree_rebalance.o \
		src/memtree/memtree_remove.o \
		src/memtree/memtree_update_height.o \
		src/mini/mini_alloc.o \
		src/mini/mini_assert.o \
		src/mini/mini_evaluate.o \
		src/mini/mini_free.o \
		src/mini/mini_get_prompt.o \
		src/mini/mini_new.o \
		src/mini/mini_print.o \
		src/mini/mini_quit.o \
		src/mini/mini_read.o \
		src/tokenizer/tokenize.o

minishell_headers = 	include/assert.h \
		include/bool.h \
		include/cstring.h \
		include/i32.h \
		include/i64.h \
		include/i8.h \
		include/list.h \
		include/mem.h \
		include/memtree.h \
		include/minishell.h \
		include/none.h \
		include/tokenizer.h \
		include/u32.h

minishell_depends = 	src/main.d \
		src/cstring/cstring_copy.d \
		src/cstring/cstring_get_length.d \
		src/cstring/cstring_join.d \
		src/cstring/cstring_to_stderr.d \
		src/memtree/memtree_create.d \
		src/memtree/memtree_destroy.d \
		src/memtree/memtree_get_height.d \
		src/memtree/memtree_insert.d \
		src/memtree/memtree_rebalance.d \
		src/memtree/memtree_remove.d \
		src/memtree/memtree_update_height.d \
		src/mini/mini_alloc.d \
		src/mini/mini_assert.d \
		src/mini/mini_evaluate.d \
		src/mini/mini_free.d \
		src/mini/mini_get_prompt.d \
		src/mini/mini_new.d \
		src/mini/mini_print.d \
		src/mini/mini_quit.d \
		src/mini/mini_read.d \
		src/tokenizer/tokenize.d

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