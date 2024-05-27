/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lua.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:43:11 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 13:12:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LUA_H
# define LUA_H

#include "minishell.h"

typedef struct lua_State	*t_lua_state;

t_none	lua_loadfile(t_mini mini, t_lua_state lua_state, t_cstring path);

#endif