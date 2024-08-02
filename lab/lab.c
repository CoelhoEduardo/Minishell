/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:45:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/23 21:22:15 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <dirent.h>
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <wait.h>

# include <readline/history.h>
# include <readline/readline.h>

int	main(void)
{
	char	*line;

    while (42)
    {
		line = readline("minishell> ");
        add_history(line);
        if (!line)
        {
            printf("Cai no break");
            break;
        }
    }
}
