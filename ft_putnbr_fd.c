/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:53:43 by mabdelba          #+#    #+#             */
/*   Updated: 2021/11/19 14:02:41 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putpositifnmb(long numb, int fd)
{
	if (numb <= 9)
	{
		ft_putchar_fd(numb + '0', fd);
	}
	else
	{
		putpositifnmb(numb / 10, fd);
		putpositifnmb(numb % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr >= 0)
		putpositifnmb(nbr, fd);
	else
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * (-1);
		putpositifnmb(nbr, fd);
	}
}
