/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:35:11 by pehenri2          #+#    #+#             */
/*   Updated: 2024/05/19 18:55:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putnbr_fd(long nbr, int fd)
{
	int		counter;

	counter = 0;
	if (nbr < 0)
	{
		counter += ft_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	if (nbr > 9)
		counter += ft_putnbr_fd(nbr / 10, fd);
	counter += ft_putchar_fd(nbr % 10 + '0', fd);
	return (counter);
}
