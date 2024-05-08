/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:54:22 by eduardocoel       #+#    #+#             */
/*   Updated: 2024/05/08 20:03:16 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int lexer(char *str, t_token **list)
{
    int type;
    int len;
    t_token *token;

    if (!str || check_open_syntax(str))
        return (set_exit_status(SYNTAX_ERROR));
    while (*str)
    {
        len = 0;
        type = get_token_type(str);
        if (type == SPACES)
            str++;
        else
        {
            len = get_token_len(str, type);
            token = token_lst_new(ft_substr(str, 0, len), type);
            token_lst_add_back(list, token);
            str += len;
        }
    }
    return (EXIT_SUCCESS);
}

int	get_token_type(char *str)
{
	if (ft_strncmp(str, "&&", 2) == 0)
		return (AND);
	else if (ft_strncmp(str, "||", 2) == 0)
		return (OR);
	else if (ft_strncmp(str, "|", 1) == 0)
		return (PIPE);
	else if (ft_strncmp(str, "(", 1) == 0)
		return (OPEN_PAREN);
	else if (ft_strncmp(str, ")", 1) == 0)
		return (CLOSE_PAREN);
	else if (ft_strncmp(str, ">>", 2) == 0)
		return (REDIR_APPEND);
	else if (ft_strncmp(str, "<<", 2) == 0)
		return (REDIR_HEREDOC);
	else if (ft_strncmp(str, "<", 1) == 0)
		return (REDIR_IN);
	else if (ft_strncmp(str, ">", 1) == 0)
		return (REDIR_OUT);
	else if (ft_isspace(*str))
		return (SPACES);
	else if (ft_strncmp(str, "\0", 1) == 0)
		return (END);
	else
		return (WORD);
}

int	get_token_length(char *str, int type)
{
	if (type == OPEN_PAREN || type == CLOSE_PAREN || type == PIPE
		|| type == REDIR_IN || type == REDIR_OUT)
		return (1);
	else if (type == AND || type == OR || type == REDIR_APPEND
		|| type == REDIR_HEREDOC)
		return (2);
	else if (type == WORD)
		return (get_word_length(str));
	return (0);
}

int	get_word_length(char *str)
{
	int	len;

	len = 0;
	while (get_token_type(str + len) == WORD)
	{
		if (str[len] == '\'')
		{
			len++;
			while (str[len] != '\'')
				len++;
		}
		if (str[len] == '\"')
		{
			len++;
			while (str[len] != '\"')
				len++;
		}
		len++;
	}
	return (len);
}
