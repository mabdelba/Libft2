/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:16:02 by mabdelba          #+#    #+#             */
/*   Updated: 2021/11/19 14:09:46 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_long(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tab;
	unsigned int	i;
	size_t			j;
	size_t			longueur;

	i = 0;
	if (!s)
		return (NULL);
	longueur = ft_long(s);
	if (len >= longueur)
		len = longueur;
	tab = (char *)malloc((len + 1) * sizeof (char));
	if (tab == 0)
		return (0);
	i = start;
	j = 0;
	while (s[i] && j < len && start <= longueur)
	{
		tab[j] = ((char *)s)[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}
