/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:10:50 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/07/23 21:00:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_heredoc_file(t_token *token)
{
	int		*heredoc_counter;
	int		fd;
	char	*file_name;
	bool	is_expandable;

	if (setup_signal_handler(heredoc_signal_handler) != SUCCESS)
		return (signal_error());
	is_expandable = false;
	heredoc_counter = get_heredoc_counter();
	file_name = ft_strjoin("/tmp/.heredoc", ft_itoa((*heredoc_counter)++));
	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (set_exit_status(handle_error("failed to create heredoc")));
	if (!ft_strchr(token->value, '\"') && !ft_strchr(token->value, '\''))
		is_expandable = true;
	token->value = remove_quotes(token->value);
	while (42)
		if (write_input_to_heredoc(fd, token->value, is_expandable) == SUCCESS)
			break ;
	if (*get_exit_status() == SIGINT + 128)
		return (set_exit_status(SIGINT + 128));
	close(fd);
	token->value = file_name;
	return (SUCCESS);
}

int	write_input_to_heredoc(int fd, char *end_condition, int is_expandable)
{
	char	*line;

	line = readline("> ");
	if (!line)
	{
		if (*get_exit_status() != SIGINT + 128)
			ft_fprintf(STDERR_FILENO,
				"minishell: warning: here-document delimited by end-of-file (wanted '%s) \n",
				end_condition);
		return (SUCCESS);
	}
	if (ft_strcmp(line, end_condition) == SUCCESS)
		return (SUCCESS);
	if (is_expandable)
		line = expand_vars(line);
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(line);
	return (FAILURE);
}

int	delete_heredoc_files(void)
{
	char	*file_name;
	int		*heredoc_counter;

	heredoc_counter = get_heredoc_counter();
	while ((*heredoc_counter) >= 0)
	{
		file_name = ft_strjoin("/tmp/.heredoc", ft_itoa((*heredoc_counter)--));
		unlink(file_name);
	}
	return (SUCCESS);
}

int	*get_heredoc_counter(void)
{
	static int counter;

	return (&counter);
}