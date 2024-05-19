/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:16:40 by leduard2          #+#    #+#             */
/*   Updated: 2024/05/19 18:55:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_words(char **str)
{
	int	i;

	i = 0;
	ft_printf("{");
	while (str[i])
	{
		ft_printf("\"%s\", ", str[i]);
		i++;
	}
	if (str[i] == NULL)
		ft_printf("\"NULL\"");
	ft_printf("}\n");
}
