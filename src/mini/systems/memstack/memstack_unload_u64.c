/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_unload_u64.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:29:44 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_u64	memstack_unload_u64(t_mini mini)
{
	t_u64	value;

	mini->memstack->top -= sizeof(t_u64);
	if (mini->memstack->top < mini->memstack->bottom)
	{
		write(STDERR_FILENO, "Memstack underflow!\n", 20);
		mini_quit(mini);
	}
	value = *((t_u64 *)(mini->memstack->top));
	return (value);
}
