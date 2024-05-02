/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_execution_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:40:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/02 15:44:04 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "types.h"
#include "linked_list.h"
#include "binary_tree.h"

t_binary_tree	build_execution_tree(t_linked_list list)
{
	t_binary_tree	execution_tree;
	
	execution_tree = new_binary_tree(NULL);
	split_tokens_into_tree(execution_tree, list);
	return (execution_tree);	
}
