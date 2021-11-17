/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:48:11 by snarain           #+#    #+#             */
/*   Updated: 2021/11/17 18:01:18 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*newline(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	free(buffer);
	return (str);
}

void	savecheck(char *save)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	i++;
	while (save[i])
		save[j++] = save[i++];
	save[j] = 0;
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			ret;

	ret = 1;
	*line = ft_strdupg("");
	*line = ft_strjoing(*line, buffer);
	while (ft_strchrg(*line, '\n') == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = 0;
		if (ret == -1)
			return (-1);
		if (ret == 0)
			break ;
		*line = ft_strjoing(*line, buffer);
	}
	if (ft_strchrg(*line, '\n') == 1)
		*line = newline(*line);
	if (ret == 0)
		return (ft_bzerog(buffer));
	savecheck(buffer);
	return (1);
}
