/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:02:07 by iren              #+#    #+#             */
/*   Updated: 2023/02/25 18:02:23 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_msg(int nb, char *s, int fd, int ret_value)
{
	if (fd == 2)
		ft_putstr_fd("Error\n", 2);
	if (nb >= 0)
	{
		ft_putnbr_fd(nb, fd);
		ft_putstr_fd(" ", fd);
	}
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\n", fd);
	return (ret_value);
}
