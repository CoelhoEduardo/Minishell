/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/29 16:27:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_env(t_token *cmd)
{
	int	i;

	if (cmd->next)
		return (!!write(STDERR_FILENO, "env: too many arguments", 24));
	i = 0;
	while (__environ[i])
	{
		if (ft_strchr(__environ[i], '='))
			ft_fprintf(STDOUT_FILENO, "%s\n", __environ[i]);
		i++;
	}
	return (SUCCESS);
}
