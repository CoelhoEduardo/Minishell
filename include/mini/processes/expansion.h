/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:31:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 00:29:56 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "minishell.h"

typedef struct s_expansion_process	*t_expansion_process;
typedef t_expansion_process			t_expansion;

struct s_expansion_process {
	t_mini_list	tokens;
};

t_none	mini_expansion_create(t_mini mini);

#endif