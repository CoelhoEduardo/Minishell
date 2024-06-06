/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_get_cwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:55:08 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/31 18:27:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	mini_get_cwd(t_mini mini)
{
	t_cstring	cwd;
	t_u32		cwd_size;

	cwd_size = 1024;
	cwd = malloc(cwd_size);
	if (cwd == NULL)
	{
		cstring_to_stderr("Memory allocation failed.\n");
		mini->exit_status = 1;
		mini_quit(mini);
	}
	while (getcwd(cwd, cwd_size) == NULL)
	{
		cwd_size *= 2;
		cwd = malloc(cwd_size);
		if (cwd == NULL)
		{
			cstring_to_stderr("Memory allocation failed.\n");
			mini->exit_status = 1;
			mini_quit(mini);
		}
	}
	// mini->cwd = cwd;
}
