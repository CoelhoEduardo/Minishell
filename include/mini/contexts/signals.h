/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:59:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/19 12:40:48 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"

typedef struct s_signals_context	*t_signals_context;
typedef t_signals_context			t_signals;
typedef struct sigaction			*t_sigaction;

struct s_signals_context {
	t_sigaction	sigaction;
};

t_none	mini_signals_create(t_mini mini);
t_none	mini_signals_sigint_handler(t_i32 sig);

#endif