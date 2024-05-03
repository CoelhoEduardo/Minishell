/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:51:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/03 15:32:34 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_minishell	mini;

	mini = new_minishell();
	while (42)
	{
		mini->line = NULL;
		mini->line = readline(PROMPT);
		if (mini->line == NULL)
			return (!write(STDOUT_FILENO, "exit\n", 5));
		else if (mini->line[0] != '\0')
		{
			add_history(mini->line);
			if (lexer(mini) == SUCCESS)
			{
				if (parser(mini) == SUCCESS)
					set_exit_status(executor(mini));
			}
		}
		reset_for_next_iteration(mini->line);
	}
}
