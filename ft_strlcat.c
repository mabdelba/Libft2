/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:56:48 by mabdelba          #+#    #+#             */
/*   Updated: 2021/11/19 15:14:39 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	z;
	size_t	sav_ldst;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	z = 0;
	if (dstsize < lendst)
		return (lensrc + dstsize);
	else
	{
		sav_ldst = lendst;
		while (src[z] && lendst + 1 < dstsize)
		{
			dst[lendst] = src[z];
			lendst++;
			z++;
		}
		dst[lendst] = '\0';
		return (lensrc + sav_ldst);
	}
}
