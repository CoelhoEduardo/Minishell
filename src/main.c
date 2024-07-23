/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:10:50 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/07/23 19:17:08 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	leave_program(int status)
{
	free_env();
	ft_free_memory();
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		write(STDOUT_FILENO, "exit\n", 5);
	rl_clear_history();
	return (status);
}

void	reset_for_next_iteration(char *line)
{
	termios_properties();
	free(line);
	delete_heredoc_file();
	ft_free_memory();
}

char	*init_and_wait_input(t_token **list)
{
	char	*line;

	if (setup_signal_handler(main_singal_handler) != SUCCESS)
	{
		free_env();
		ft_free_memory();
		exit(signal_error());
	};
	*list = NULL;
	line = readline("minishell> ");
	return (line);
}

void	termios_properties(void)
{
	static struct termios	term;
	static int				term_saved;

	term_saved = 0;
	if (term_saved)
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
	else
	{
		tcgetattr(STDIN_FILENO, &term);
		term_saved = 1;
	}
}

int	main(void)
{
	char		*line;
	t_token		*list;
	t_tree_node	*root;

	init_environ();
	termios_properties();
	while (42)
	{
		line = init_and_wait_input(&list);
		if (!line)
			break ;
		else if (*line != '\0') // line[0] != '\0'
		{
			add_history(line);
			if (lexer(line, &list) == SUCCESS)
			{
				if (parser(list, &root) == SUCCESS)
					set_exit_status(executor(root));
			}
		}
		reset_for_next_iteration(line);
	}
	return (leave_program(SUCCESS));
}
