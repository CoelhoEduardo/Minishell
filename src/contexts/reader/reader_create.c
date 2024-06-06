/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:22:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/05 21:29:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	reader_create(t_mini mini)
{
	mini->reader = mini_alloc(mini, sizeof(struct s_reader_context));
	mini->reader->line = NULL;
	mini->reader->prompt = NULL;
	mini->reader->is_complete = FALSE;
}