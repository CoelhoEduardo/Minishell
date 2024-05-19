/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:33:36 by pehenri2          #+#    #+#             */
/*   Updated: 2024/05/19 18:55:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_words(const char *string, const char delimiter)
{
	int	word_count;

	if (*string == '\0' || string == NULL)
		return (0);
	word_count = 0;
	while (*string != '\0')
	{
		if (*string != delimiter)
		{
			word_count++;
			while ((*string != delimiter) && (*string != '\0'))
				string++;
		}
		else
			string++;
	}
	return (word_count);
}
