/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstack_load_i64.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:27:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 21:28:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	memstack_load_i64(t_mini mini, t_i64 value)
{
	t_u8	byte;
	t_i32	counter;

	counter = 0;
	while (counter < sizeof(t_i64))
	{
		byte = ((t_u8 *)(&value))[counter];
		memstack_load(mini, byte);
		counter++;
	}
}
