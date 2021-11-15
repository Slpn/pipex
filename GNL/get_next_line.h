/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:23:34 by snarain           #+#    #+#             */
/*   Updated: 2021/11/15 19:11:36 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 12

void	savecheck(char *save);

int		get_next_line(int fd, char **line);
int		ft_strchrg(char *s, char c);
int		ft_strleng(char *s);
int		ft_bzerog(void *s);

char	*ft_strdupg(char *s);
char	*newline(char *buffer);
char	*ft_strjoing(char *s1, char *s2);

#endif
