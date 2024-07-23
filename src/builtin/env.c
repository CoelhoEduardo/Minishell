/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:33:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/22 21:58:31 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_env(t_token *cmd)
{
	int		i;
	char	**env;

	env = *get_my_env();
	if (cmd->next)
		return (!!write(STDERR_FILENO, "env: too many arguments", 23));
	i = -1;
	while (env[++i])
	{
		if (env[i][0] && ft_strchr(env[i], '='))
			ft_fprintf(STDOUT_FILENO, "%s\n", env[i]);
	}
	return (SUCCESS);
}
