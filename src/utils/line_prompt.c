/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:48:50 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/08/07 20:48:22 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*ft_strcat(char *dest, const char *src)
{
	size_t	dest_len;
	size_t	i;

	dest_len = strlen(dest);
    i = 0;
    while (src[i])
    {
        dest[dest_len + i] = src[i];
        i++;
    }
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
	dest[i] = '\0';
	return (dest);
}

char	*cut_pwd(char *path)
{
	const char	*first_slash;
	const char	*second_slash;
	char		*new_pwd;

	first_slash = ft_strdup(ft_strchr(path, '/') + 1);
	second_slash = ft_strchr(first_slash, '/');
	if (second_slash == NULL)
		new_pwd = ft_strdup(path);
	else
		new_pwd = ft_strdup(second_slash + 1);
	free(path);
	return (new_pwd);
}

char	*prompt_line(void)
{
	char	*cwd;
	char	*end_line;
	char	*final;
	char	*name;
	size_t	total_len;

	name = "minishell:~/";
	end_line = "⚡️ ";
	cwd = cut_pwd(getcwd(NULL, 0));
	total_len = ft_strlen(name) + ft_strlen(cwd) + strlen(end_line) + 1;
	final = malloc(total_len);
	if (!final)
		return (NULL);
	ft_strcpy(final, name);
	ft_strcat(final, cwd);
	ft_strcat(final, end_line);
	// free(cwd);
	ft_collect_mem(final);
	return (final);
}
