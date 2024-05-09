/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_for_next_iteration.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:22:40 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/09 16:27:21 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "binary_tree.h"
#include "linked_list.h"

void	reset_for_next_iteration(t_minishell mini)
{
	free(mini->line);
	destroy_binary_tree(mini, mini->tree);
	destroy_linked_list(mini, mini->list);
	mini->tree = NULL;
	mini->list = NULL;
}
