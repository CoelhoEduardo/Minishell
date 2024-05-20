# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 09:59:11 by bhildebr          #+#    #+#              #
#    Updated: 2024/05/20 09:59:11 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline

minishell_sources = 	src/main.c \
		src/builtin/export.c \
		src/executor/execute_command.c \
		src/executor/executor.c \
		src/lexer/lexer.c \
		src/lexer/open_syntax.c \
		src/libft/ft_absolute.c \
		src/libft/ft_arrstr_len.c \
		src/libft/ft_atoi.c \
		src/libft/ft_atoi_base.c \
		src/libft/ft_atol.c \
		src/libft/ft_bzero.c \
		src/libft/ft_calloc.c \
		src/libft/ft_collect_mem.c \
		src/libft/ft_count_words.c \
		src/libft/ft_dlst_add_back.c \
		src/libft/ft_dlst_add_front.c \
		src/libft/ft_dlst_last.c \
		src/libft/ft_dlst_new.c \
		src/libft/ft_dlst_size.c \
		src/libft/ft_eval_format.c \
		src/libft/ft_fprintf.c \
		src/libft/ft_freepp.c \
		src/libft/ft_free_ptr_array.c \
		src/libft/ft_free_str.c \
		src/libft/ft_free_str_array.c \
		src/libft/ft_isalnum.c \
		src/libft/ft_isalpha.c \
		src/libft/ft_isascii.c \
		src/libft/ft_isdigit.c \
		src/libft/ft_isprint.c \
		src/libft/ft_issign.c \
		src/libft/ft_isspace.c \
		src/libft/ft_itoa.c \
		src/libft/ft_lstadd_back.c \
		src/libft/ft_lstadd_back_arr.c \
		src/libft/ft_lstadd_front.c \
		src/libft/ft_lstclear.c \
		src/libft/ft_lstdelone.c \
		src/libft/ft_lstiter.c \
		src/libft/ft_lstlast.c \
		src/libft/ft_lstmap.c \
		src/libft/ft_lstnew.c \
		src/libft/ft_lstsize.c \
		src/libft/ft_maxval.c \
		src/libft/ft_memchr.c \
		src/libft/ft_memcmp.c \
		src/libft/ft_memcpy.c \
		src/libft/ft_memmove.c \
		src/libft/ft_memset.c \
		src/libft/ft_nbrlen.c \
		src/libft/ft_printf.c \
		src/libft/ft_print_char.c \
		src/libft/ft_print_digit.c \
		src/libft/ft_print_ex.c \
		src/libft/ft_print_ex_up.c \
		src/libft/ft_print_pointer.c \
		src/libft/ft_print_str.c \
		src/libft/ft_print_unsigned.c \
		src/libft/ft_print_utils.c \
		src/libft/ft_print_words.c \
		src/libft/ft_putchar_fd.c \
		src/libft/ft_putendl_fd.c \
		src/libft/ft_putnbr_base_fd.c \
		src/libft/ft_putnbr_fd.c \
		src/libft/ft_putptr_fd.c \
		src/libft/ft_putstr_fd.c \
		src/libft/ft_quote_add_word.c \
		src/libft/ft_quote_count_words.c \
		src/libft/ft_quote_get_len.c \
		src/libft/ft_quote_move_next_word.c \
		src/libft/ft_quote_split.c \
		src/libft/ft_split.c \
		src/libft/ft_strchr.c \
		src/libft/ft_strchr_quote_aware.c \
		src/libft/ft_strcmp.c \
		src/libft/ft_strdup.c \
		src/libft/ft_strdup_calloc.c \
		src/libft/ft_striteri.c \
		src/libft/ft_strjoin.c \
		src/libft/ft_strlcat.c \
		src/libft/ft_strlcpy.c \
		src/libft/ft_strlen.c \
		src/libft/ft_strmapi.c \
		src/libft/ft_strncmp.c \
		src/libft/ft_strndup.c \
		src/libft/ft_strnstr.c \
		src/libft/ft_strrchr.c \
		src/libft/ft_strtolower.c \
		src/libft/ft_strtoupper.c \
		src/libft/ft_strtrim.c \
		src/libft/ft_substr.c \
		src/libft/ft_tolower.c \
		src/libft/ft_toupper.c \
		src/libft/ft_wordcount.c \
		src/libft/get_next_line.c \
		src/parser/parser.c \
		src/signals/signals.c \
		src/utils/environ.c \
		src/utils/error.c \
		src/utils/helper.c \
		src/utils/token_list.c

minishell_objects = 	src/main.o \
		src/builtin/export.o \
		src/executor/execute_command.o \
		src/executor/executor.o \
		src/lexer/lexer.o \
		src/lexer/open_syntax.o \
		src/libft/ft_absolute.o \
		src/libft/ft_arrstr_len.o \
		src/libft/ft_atoi.o \
		src/libft/ft_atoi_base.o \
		src/libft/ft_atol.o \
		src/libft/ft_bzero.o \
		src/libft/ft_calloc.o \
		src/libft/ft_collect_mem.o \
		src/libft/ft_count_words.o \
		src/libft/ft_dlst_add_back.o \
		src/libft/ft_dlst_add_front.o \
		src/libft/ft_dlst_last.o \
		src/libft/ft_dlst_new.o \
		src/libft/ft_dlst_size.o \
		src/libft/ft_eval_format.o \
		src/libft/ft_fprintf.o \
		src/libft/ft_freepp.o \
		src/libft/ft_free_ptr_array.o \
		src/libft/ft_free_str.o \
		src/libft/ft_free_str_array.o \
		src/libft/ft_isalnum.o \
		src/libft/ft_isalpha.o \
		src/libft/ft_isascii.o \
		src/libft/ft_isdigit.o \
		src/libft/ft_isprint.o \
		src/libft/ft_issign.o \
		src/libft/ft_isspace.o \
		src/libft/ft_itoa.o \
		src/libft/ft_lstadd_back.o \
		src/libft/ft_lstadd_back_arr.o \
		src/libft/ft_lstadd_front.o \
		src/libft/ft_lstclear.o \
		src/libft/ft_lstdelone.o \
		src/libft/ft_lstiter.o \
		src/libft/ft_lstlast.o \
		src/libft/ft_lstmap.o \
		src/libft/ft_lstnew.o \
		src/libft/ft_lstsize.o \
		src/libft/ft_maxval.o \
		src/libft/ft_memchr.o \
		src/libft/ft_memcmp.o \
		src/libft/ft_memcpy.o \
		src/libft/ft_memmove.o \
		src/libft/ft_memset.o \
		src/libft/ft_nbrlen.o \
		src/libft/ft_printf.o \
		src/libft/ft_print_char.o \
		src/libft/ft_print_digit.o \
		src/libft/ft_print_ex.o \
		src/libft/ft_print_ex_up.o \
		src/libft/ft_print_pointer.o \
		src/libft/ft_print_str.o \
		src/libft/ft_print_unsigned.o \
		src/libft/ft_print_utils.o \
		src/libft/ft_print_words.o \
		src/libft/ft_putchar_fd.o \
		src/libft/ft_putendl_fd.o \
		src/libft/ft_putnbr_base_fd.o \
		src/libft/ft_putnbr_fd.o \
		src/libft/ft_putptr_fd.o \
		src/libft/ft_putstr_fd.o \
		src/libft/ft_quote_add_word.o \
		src/libft/ft_quote_count_words.o \
		src/libft/ft_quote_get_len.o \
		src/libft/ft_quote_move_next_word.o \
		src/libft/ft_quote_split.o \
		src/libft/ft_split.o \
		src/libft/ft_strchr.o \
		src/libft/ft_strchr_quote_aware.o \
		src/libft/ft_strcmp.o \
		src/libft/ft_strdup.o \
		src/libft/ft_strdup_calloc.o \
		src/libft/ft_striteri.o \
		src/libft/ft_strjoin.o \
		src/libft/ft_strlcat.o \
		src/libft/ft_strlcpy.o \
		src/libft/ft_strlen.o \
		src/libft/ft_strmapi.o \
		src/libft/ft_strncmp.o \
		src/libft/ft_strndup.o \
		src/libft/ft_strnstr.o \
		src/libft/ft_strrchr.o \
		src/libft/ft_strtolower.o \
		src/libft/ft_strtoupper.o \
		src/libft/ft_strtrim.o \
		src/libft/ft_substr.o \
		src/libft/ft_tolower.o \
		src/libft/ft_toupper.o \
		src/libft/ft_wordcount.o \
		src/libft/get_next_line.o \
		src/parser/parser.o \
		src/signals/signals.o \
		src/utils/environ.o \
		src/utils/error.o \
		src/utils/helper.o \
		src/utils/token_list.o

minishell_headers = 	include/minishell.h

minishell_depends = 	src/main.d \
		src/builtin/export.d \
		src/executor/execute_command.d \
		src/executor/executor.d \
		src/lexer/lexer.d \
		src/lexer/open_syntax.d \
		src/libft/ft_absolute.d \
		src/libft/ft_arrstr_len.d \
		src/libft/ft_atoi.d \
		src/libft/ft_atoi_base.d \
		src/libft/ft_atol.d \
		src/libft/ft_bzero.d \
		src/libft/ft_calloc.d \
		src/libft/ft_collect_mem.d \
		src/libft/ft_count_words.d \
		src/libft/ft_dlst_add_back.d \
		src/libft/ft_dlst_add_front.d \
		src/libft/ft_dlst_last.d \
		src/libft/ft_dlst_new.d \
		src/libft/ft_dlst_size.d \
		src/libft/ft_eval_format.d \
		src/libft/ft_fprintf.d \
		src/libft/ft_freepp.d \
		src/libft/ft_free_ptr_array.d \
		src/libft/ft_free_str.d \
		src/libft/ft_free_str_array.d \
		src/libft/ft_isalnum.d \
		src/libft/ft_isalpha.d \
		src/libft/ft_isascii.d \
		src/libft/ft_isdigit.d \
		src/libft/ft_isprint.d \
		src/libft/ft_issign.d \
		src/libft/ft_isspace.d \
		src/libft/ft_itoa.d \
		src/libft/ft_lstadd_back.d \
		src/libft/ft_lstadd_back_arr.d \
		src/libft/ft_lstadd_front.d \
		src/libft/ft_lstclear.d \
		src/libft/ft_lstdelone.d \
		src/libft/ft_lstiter.d \
		src/libft/ft_lstlast.d \
		src/libft/ft_lstmap.d \
		src/libft/ft_lstnew.d \
		src/libft/ft_lstsize.d \
		src/libft/ft_maxval.d \
		src/libft/ft_memchr.d \
		src/libft/ft_memcmp.d \
		src/libft/ft_memcpy.d \
		src/libft/ft_memmove.d \
		src/libft/ft_memset.d \
		src/libft/ft_nbrlen.d \
		src/libft/ft_printf.d \
		src/libft/ft_print_char.d \
		src/libft/ft_print_digit.d \
		src/libft/ft_print_ex.d \
		src/libft/ft_print_ex_up.d \
		src/libft/ft_print_pointer.d \
		src/libft/ft_print_str.d \
		src/libft/ft_print_unsigned.d \
		src/libft/ft_print_utils.d \
		src/libft/ft_print_words.d \
		src/libft/ft_putchar_fd.d \
		src/libft/ft_putendl_fd.d \
		src/libft/ft_putnbr_base_fd.d \
		src/libft/ft_putnbr_fd.d \
		src/libft/ft_putptr_fd.d \
		src/libft/ft_putstr_fd.d \
		src/libft/ft_quote_add_word.d \
		src/libft/ft_quote_count_words.d \
		src/libft/ft_quote_get_len.d \
		src/libft/ft_quote_move_next_word.d \
		src/libft/ft_quote_split.d \
		src/libft/ft_split.d \
		src/libft/ft_strchr.d \
		src/libft/ft_strchr_quote_aware.d \
		src/libft/ft_strcmp.d \
		src/libft/ft_strdup.d \
		src/libft/ft_strdup_calloc.d \
		src/libft/ft_striteri.d \
		src/libft/ft_strjoin.d \
		src/libft/ft_strlcat.d \
		src/libft/ft_strlcpy.d \
		src/libft/ft_strlen.d \
		src/libft/ft_strmapi.d \
		src/libft/ft_strncmp.d \
		src/libft/ft_strndup.d \
		src/libft/ft_strnstr.d \
		src/libft/ft_strrchr.d \
		src/libft/ft_strtolower.d \
		src/libft/ft_strtoupper.d \
		src/libft/ft_strtrim.d \
		src/libft/ft_substr.d \
		src/libft/ft_tolower.d \
		src/libft/ft_toupper.d \
		src/libft/ft_wordcount.d \
		src/libft/get_next_line.d \
		src/parser/parser.d \
		src/signals/signals.d \
		src/utils/environ.d \
		src/utils/error.d \
		src/utils/helper.d \
		src/utils/token_list.d

minishell_includes = 	-iquote include

all:
	@./script/generate_makefile > /dev/null 2>&1
	@$(MAKE) --no-print-directory $(NAME) 2>&1 | sed 's/^make\[[0-9]*\]:/make:/'

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