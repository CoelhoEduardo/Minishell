/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pipe_tree_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:04:16 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 21:39:45 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_pipe_tree_destroy(t_mini mini, t_mini_pipe_tree tree)
{
	mini_cmd_tree_list_destroy(mini, tree->command_list);
	mini_free(mini, tree);
}
