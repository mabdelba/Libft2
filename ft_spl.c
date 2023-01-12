/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:36:37 by mabdelba          #+#    #+#             */
/*   Updated: 2023/01/04 22:53:29 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_length(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (const char)c && s[i] != '\t' && s[i] != '\n')
		i++;
	return (i);
}

static int	ft_nbrstrs(const char *s, char c)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (s[i])
	{
		while (s[i] == (const char)c || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i] != '\0')
			compt++;
		while (s[i] && s[i] != (const char)c && s[i] != '\t' && s[i] != '\n')
			i++;
	}
	return (compt);
}

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	ft_initial(unsigned int *i, int *j)
{
	*i = -1;
	*j = -1;
}

char	**ft_spl(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	int				j;

	if (!s)
		return (NULL);
	tab = (char **) malloc((ft_nbrstrs(s, c) + 1) * sizeof(char *));
	if (tab == 0)
		return (NULL);
	ft_initial(&i, &j);
	while (s[++i])
	{
		if (s[i] != c && s[i] != '\t' && s[i] != '\n')
		{
			tab[++j] = ft_substr(s, i, ft_length(s + i, c));
			if (!tab[j])
			{
				ft_free(tab);
				return (NULL);
			}
			i = i + ft_length(s + i, c) - 1;
		}
	}
	tab[++j] = 0;
	return (tab);
}
