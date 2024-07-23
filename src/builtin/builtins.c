/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:12:31 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/22 21:19:11 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_builtin(t_token *cmd)
{
	if (!ft_strcmp(cmd->value, "cd") || !ft_strcmp(cmd->value, "echo")
		|| !ft_strcmp(cmd->value, "env") || !ft_strcmp(cmd->value, "exit")
		|| !ft_strcmp(cmd->value, "export") || !ft_strcmp(cmd->value, "pwd")
		|| !ft_strcmp(cmd->value, "unset"))
		return (true);
	return (false);
}

int	execute_builtin(t_token *cmd)
{
	if (!ft_strcmp(cmd->value, "cd"))
		return (execute_cd(cmd));
	if (!ft_strcmp(cmd->value, "echo"))
		return (execute_echo(cmd));
	if (!ft_strcmp(cmd->value, "env"))
		return (execute_env(cmd));
	if (!ft_strcmp(cmd->value, "exit"))
		return (execute_exit(cmd));
	if (!ft_strcmp(cmd->value, "export"))
		return (execute_export(cmd));
	if (!ft_strcmp(cmd->value, "pwd"))
		return (execute_pwd());
	if (!ft_strcmp(cmd->value, "unset"))
		return (execute_unset(cmd));
	return (handle_error("error executing builtin"));
}
