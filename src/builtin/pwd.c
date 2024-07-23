/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:51:18 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/22 21:59:38 by ecoelho-         ###   ########.fr       */
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
		return (handle_error("pwd"));
}
