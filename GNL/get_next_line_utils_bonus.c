/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:00:37 by snarain           #+#    #+#             */
/*   Updated: 2021/06/09 15:37:13 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_bzero(void *s)
{
	if (!s)
		return (0);
	while (*(unsigned char *)s)
		*(unsigned char *)(s++) = 0;
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = ft_strlen(s1) + ft_strlen(s2);
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

int	ft_strchr(char *s, char c)
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

char	*ft_strdup(char *s)
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
