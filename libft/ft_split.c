/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 00:24:05 by snarain           #+#    #+#             */
/*   Updated: 2021/04/05 22:56:01 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sizeword(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

int	count_word(char	const *s, char c)
{
	int	state;
	int	word;

	word = 0;
	state = 1;
	while (*s)
	{
		if (*s == c)
			state = 1;
		else
		{
			if (state == 1)
				word++;
			state = 0;
		}
		s++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		words;

	words = count_word(s, c);
	tab = malloc(sizeof(char *) * words + 1);
	if (!tab)
		return (NULL);
	i = -1;
	while (*s && ++i < words)
	{
		while (*s && *s == c)
			s++;
		tab[i] = malloc(sizeof(char) * sizeword(s, c) + 1);
		if (!tab[i])
			return (NULL);
		j = 0;
		while (*s && *s != c)
			tab[i][j++] = *s++;
		tab[i][j] = 0;
	}
	tab[words] = 0;
	return (tab);
}
