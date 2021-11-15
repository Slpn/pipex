/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:58:50 by snarain           #+#    #+#             */
/*   Updated: 2021/06/14 12:40:06 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	str[i] = '\0';
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (str);
}

void	savecheck(char *save)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (save[i] != '\n')
		i++;
	i++;
	while (save[i])
		save[j++] = save[i++];
	while (save[j])
		save[j++] = 0;
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 0 || read(fd, buffer[0], 0) == -1)
		return (-1);
	ret = 1;
	*line = ft_strdup("");
	*line = ft_strjoin(*line, buffer[fd]);
	while ((ft_strchr(*line, '\n') == 0) && ret != 0)
	{
		ret = read(fd, buffer[fd], BUFFER_SIZE);
		buffer[fd][ret] = '\0';
		if (ret == -1)
			return (-1);
		if (ret == 0)
			break ;
		*line = ft_strjoin(*line, buffer[fd]);
	}
	if (ft_strchr(*line, '\n') == 1)
		*line = newline(*line);
	if (ret == 0)
		return (ft_bzero(buffer[fd]));
	savecheck(buffer[fd]);
	return (1);
}
