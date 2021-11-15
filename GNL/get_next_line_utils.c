/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:00:30 by snarain           #+#    #+#             */
/*   Updated: 2021/11/15 19:03:57 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_bzerog(void *s)
{
	if (!s)
		return (0);
	while (*(unsigned char *)s)
		*(unsigned char *)(s++) = 0;
	return (0);
}

int	ft_strleng(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoing(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = ft_strleng(s1) + ft_strleng(s2);
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	str[j] = 0;
	if (s1)
	{
		while (s1[++i])
			str[i] = s1[i];
		free(s1);
	}
	if (s2)
	{
		while (*s2)
			str[i++] = *s2++;
	}
	return (str);
}

int	ft_strchrg(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdupg(char *s)
{
	int		i;
	int		len;
	char	*s2;

	len = 0;
	while (s[len])
		len++;
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
