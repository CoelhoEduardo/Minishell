/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_load_i32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:18:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	memstack_load_i32(t_mini mini, t_i32 value)
{
	t_u8	byte;
	t_u32	counter;

	counter = 0;
	while (counter < sizeof(t_i32))
	{
		byte = ((t_u8 *)(&value))[counter];
		memstack_load(mini, byte);
		counter++;
	}
}
