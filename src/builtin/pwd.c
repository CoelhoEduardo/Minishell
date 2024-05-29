/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:32:51 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/29 16:33:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path)
	{
		ft_collect_mem(path);
		printf("%s\n", path);
		return (SUCCESS);
	}
	else
	{
		return (handle_error("pwd"));
	}
}
