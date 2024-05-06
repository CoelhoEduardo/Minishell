/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:50:11 by ecoelho-          #+#    #+#             */
/*   Updated: 2024/05/06 19:27:15 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_open_syntax(char *str)
{
    int index;
    int brackets;
    int single_quote;
    int double_quote;

    index = 0;
    brackets = 0;
    single_quote = 0;
    double_quote = 0;

    while (str[index])
    {
        if (str[index] == '(')
            brackets++;
        if (str[index] == ')')
            brackets--;
        if (str[index] == '\'' || str[index] == '\"')
            move_to_next_quote(str, &index, &single_quote, &double_quote);
        index++;
    }
    if (brackets != 0 || single_quote != 0 || double_quote != 0)
        return (write(0, "Syntax error\n", 13));
    return(0);
}

void move_to_next_quote(char *str, int *index, int *single_quote, int *double_quote)
{
    if (str[*index] == '\'')
    {
        (*single_quote)++;
        (*index)++;
        while (str[*index] && str[*index] != '\'')
            (*index)++;
        if (str[*index] == '\'')
            (*single_quote)--;
    }
    if (str[*index] == '\"')
    {
        (*double_quote)++;
        (*index)++;
        while (str[*index] && str[*index] != '\"')
            (*index)++;
        if (str[*index] == '\"')
            (*double_quote)--;
    }
}
