/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_readline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:23:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 22:10:44 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	mini_readline(t_mini mini)
{
	// t_cstring	prompt;

	// const t_cstring			prompt = mini_get_prompt(mini);
	// const t_mini_context	context = mini->mini_context; 

	// if (context->line)
	// 	mini_free(mini, context->line);
	// context->line = readline(prompt);
	// if (context->line)
	// 	memtree_insert(&(context->memtree), NULL, context->line);
	// #ifdef DEBUG
	// 	printf("\033[94m[%s:%d] (line)\n\033[0m%s\n", __func__, __LINE__, context->line);
	// #endif
	// if (context->line == NULL)
	// {
	// 	cstring_to_stdout("\033[33mAn empty line with only EOF was entered. I'm quitting.\033[0m\n");
	// 	mini_quit(mini);
	// }
	(void)mini;
}
