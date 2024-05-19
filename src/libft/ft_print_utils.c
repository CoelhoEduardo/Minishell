/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:25:59 by leduard2          #+#    #+#             */
/*   Updated: 2024/05/19 18:55:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_format	*inicialize_flags(t_format *flags)
{
	flags->wdt = 0;
	flags->prc = 0;
	flags->zero = 0;
	flags->pnt = 0;
	flags->dash = 0;
	flags->tl = 0;
	flags->sign = 0;
	flags->is_zero = 0;
	flags->perc = 0;
	flags->sp = 0;
	flags->hash = 0;
	flags->lowc = 0;
	flags->upc = 0;
	return (flags);
}
