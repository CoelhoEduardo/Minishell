/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:48:50 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/08/02 18:54:51 by ecoelho-         ###   ########.fr       */
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
	return (dest);
}

char	*cut_pwd(const char *path)
{
	const char	*first_slash;
	const char	*second_slash;

	first_slash = ft_strdup(ft_strchr(path, '/') + 1);
	second_slash = ft_strchr(first_slash, '/');
	if (second_slash == NULL)
		return (ft_strdup(path));
	else
		return (ft_strdup(second_slash + 1));
}

char	*prompt_line(void)
{
	char	*cwd;
	char	*end_line;
	char	*final;
	char	*name;
	char	*just_path;
	size_t	total_len;

	name = "minishell:~/";
	end_line = "⚡️ ";
	cwd = getcwd(NULL, 0);
	just_path = cut_pwd(cwd);
	free(cwd);
	total_len = ft_strlen(name) + ft_strlen(just_path) + strlen(end_line) + 1;
	final = malloc(total_len);
	if (final == NULL)
		return (NULL);
	ft_strcpy(final, name);
	ft_strcat(final, just_path);
	ft_strcat(final, end_line);
	return (final);
}
