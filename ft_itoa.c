/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:17:31 by mabdelba          #+#    #+#             */
/*   Updated: 2021/11/19 14:01:19 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrcases(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	nbrnegatif(int *n, int *size, int *i, int *drp)
{
	*size = nbrcases(*n);
	*i = nbrcases(*n);
	*drp = 0;
	if (*n < 0)
	{
		*n = -*n;
		*drp = 1;
	}
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		size;
	int		i;
	int		drp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nbrnegatif(&n, &size, &i, &drp);
	tab = (char *) malloc((size + drp + 1) * sizeof(char));
	if (tab == 0)
		return (0);
	while (n >= 0 && size >= drp)
	{
		tab[size - 1 + drp] = ((n % 10) + '0');
		n = n / 10;
		size--;
	}
	if (drp == 1)
		tab[0] = '-';
	tab[i + drp] = '\0';
	return (tab);
}
