/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:51:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 10:46:06 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	main(void)
{
	#ifdef DEBUG
		printf("Mini is running in \033[94mDEBUG\033[0m mode.\n");
	#endif
	t_mini	mini;

	mini = mini_new();
	mini_setup(mini);
	while (42)
	{
		mini_read(mini);
		mini_evaluate(mini);
	}
}
