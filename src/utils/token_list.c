/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:46:53 by bhildebr          #+#    #+#             */
/*   Updated: 2024/08/01 18:24:58 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_lst_new(char *value, int type)
{
	t_token	*new;

	new = ft_dalloc(sizeof(t_token), 1);
	if (!new)
		return (NULL);
	new->type = type;
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	token_lst_add_back(t_token **token_list, t_token *new)
{
	t_token	*last;

	if (!(*token_list))
		*token_list = new;
	else
	{
		last = token_lst_get_last(*token_list);
		last->next = new;
		new->prev = last;
	}
}

int	token_lst_get_size(t_token *token_list)
{
	t_token	*current;
	int		count;

	count = 0;
	current = token_list;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_token	*token_lst_get_last(t_token *token_list)
{
	t_token	*current;

	if (!token_list)
		return (NULL);
	current = token_list;
	while (current->next)
		current = current->next;
	return (current);
}

void	sort_token_lst(t_token **head)
{
	t_token	*current;
	t_token	*next;
	char	*temp;

	current = *head;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (ft_strcmp(current->value, next->value) > 0)
			{
				temp = current->value;
				current->value = next->value;
				next->value = temp;
			}
			next = next->next;
		}
		current = current->next;
	}
}
