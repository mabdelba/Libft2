/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:34:26 by mabdelba          #+#    #+#             */
/*   Updated: 2021/11/19 14:07:23 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		first_i;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		first_i = i;
		j = 0;
		while (needle[j] && haystack[i] && i < len
			&& haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		i = first_i;
		i++;
		if (needle[j] == '\0')
			return ((char *) &haystack[first_i]);
	}
	return (0);
}
