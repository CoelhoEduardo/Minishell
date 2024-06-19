/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signals_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:01:47 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/19 12:43:10 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_signals_create(t_mini mini)
{
	mini->signals = mini_alloc(mini, sizeof(struct s_signals_context));
	mini->signals->sigaction = mini_alloc(mini, sizeof(struct sigaction));
	mem_set(mini->signals->sigaction, 0, sizeof(struct sigaction));
	mini->signals->sigaction->sa_handler = mini_signals_sigint_handler;
	sigemptyset(&mini->signals->sigaction->sa_mask);
	mini->signals->sigaction->sa_flags = 0;
	sigaction(SIGINT, mini->signals->sigaction, NULL);
	signal(SIGQUIT, SIG_IGN);
}
