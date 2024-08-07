/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:38:06 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/07/21 13:38:35 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_open_syntax(char *str)
{
	int	index;
	int	brackets;
	int	single_quote;
	int	double_quote;

	index = 0;
	brackets = 0;
	single_quote = 0;
	double_quote = 0;
	while (str[index])
	{
		if (str[index] == '\'' || str[index] == '\"')
			move_to_next_quote(str, &index, &single_quote, &double_quote);
		if (str[index] == '(')
			brackets++;
		if (str[index] == ')')
			brackets--;
		index++;
	}
	if (brackets != 0 || single_quote != 0 || double_quote != 0)
		return (SYNTAX_ERROR +
				!write(STDERR_FILENO,
						"Invalid syntax, check input\
 for open quotes or brackets.\n",
						57));
	return (SUCCESS);
}

void	move_to_next_quote(char *str, int *index, int *single_quote,
		int *double_quote)
{
	if (str[*index] == '\'')
	{
		(*single_quote)++;
		(*index)++;
		while (str[*index] && str[*index] != '\'')
			(*index)++;
		if (str[*index] == '\'')
			(*single_quote)--;
	}
	if (str[*index] == '\"')
	{
		(*double_quote)++;
		(*index)++;
		while (str[*index] && str[*index] != '\"')
			(*index)++;
		if (str[*index] == '\"')
			(*double_quote)--;
	}
}
