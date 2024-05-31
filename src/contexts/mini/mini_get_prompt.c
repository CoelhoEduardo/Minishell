/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_get_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:47:04 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

#ifdef CUSTOM_PROMPT

static t_cstring	get_custom_prompt(t_mini mini)
{
	(void)mini;
	#ifdef LUA
		return (mini->config_context->prompt);
	#endif
	return (PROMPT);
}

t_cstring	mini_get_prompt(t_mini mini)
{
	t_cstring	prompt;

	if (mini_check_flag(mini, MINI_FLAG_MULTILINE))
	{
		prompt = MULTILINE_PROMPT;
	}
	else
	{
		prompt = get_custom_prompt(mini);
	}
	return (prompt);
}

#else

t_cstring	mini_get_prompt(t_mini mini)
{
	t_cstring	prompt;

	if (mini_check_flag(mini, MINI_FLAG_MULTILINE))
	{
		prompt = MULTILINE_PROMPT;
	}
	else
	{
	prompt = PROMPT;
	}
	return (prompt);
}

#endif