/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:29:51 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/20 17:55:18 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_cd(t_token *cmd)
{
	char	**args;

	if (token_lst_get_size(cmd) > 2)
		return (!!write(STDERR_FILENO, "cd: too many arguments\n", 23));
	args = get_cmd_and_args(cmd);
	if (!args[1] || !ft_strcmp(args[1], "~"))
		return (change_to_home());
	return (change_dir(args[1]));
}

int	change_to_home(void)
{
	char	*home;
	char	*cur_dir;

	cur_dir = getcwd(NULL, 0);
	ft_collect_mem(cur_dir);
	home = getenv("HOME");
	if (home)
	{
		if (chdir(home) == -1)
			return (handle_error(home));
		set_env(ft_strjoin("OLDPWD=", cur_dir), "OLDPWD", cur_dir);
		set_env(ft_strjoin("PWD=", getcwd(NULL, 0)), "PWD", getcwd(NULL, 0));
		return (SUCCESS);
	}
	else
		return (!!write(STDERR_FILENO, "cd: HOME not set\n", 17));
}

int	change_dir(char *path)
{
	char	*cur_dir;

	cur_dir = getcwd(NULL, 4096);
	if (!cur_dir)
		return (handle_error("cd"));
	ft_collect_mem(cur_dir);
	if (check_access(path) == FAILURE)
		return (FAILURE);
	if (chdir(path) == -1)
		return (handle_error(path));
	set_env(ft_strjoin("OLDPWD=", cur_dir), "OLDPWD", cur_dir);
	set_env(ft_strjoin("PWD=", getcwd(NULL, 0)), "PWD", getcwd(NULL, 0));
	return (SUCCESS);
}

int	check_access(char *path)
{
	if (access(path, F_OK))
		return (!!ft_fprintf(STDERR_FILENO, "cd: %s: no such file or\
 directory\n", path));
	else if (access(path, R_OK))
		return (!!ft_fprintf(STDERR_FILENO, "cd: %s: permission denied\n",
				path));
	return (SUCCESS);
}
