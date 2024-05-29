/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:19:22 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/29 15:42:47 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "minishell.h"

typedef struct s_string	*t_string;

struct s_string {
	t_cstring	content;
	t_u32		length;
};

t_string	string_new();
t_string	string_delete();

#endif