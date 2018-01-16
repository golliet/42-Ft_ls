/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:00:40 by golliet           #+#    #+#             */
/*   Updated: 2017/11/15 09:57:38 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_words(char const *s, char c)
{
	int count;
	int i;

	if (s == NULL)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static	int	ft_number_of_letters(char const *s, char c)
{
	int i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = (char*)s;
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_number_words(s, c) + 1)))
			|| s == NULL)
		return (NULL);
	while (i < ft_number_words(s, c))
	{
		while (*str == c)
			str++;
		if (!(tab[i] = (char*)malloc(sizeof(char)
						* ft_number_of_letters(str, c))))
			return (NULL);
		j = -1;
		while (++j < ft_number_of_letters(str, c))
			tab[i][j] = str[j];
		tab[i++][j] = '\0';
		str += j;
	}
	tab[i] = NULL;
	return (tab);
}
