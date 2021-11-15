#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

void	savecheck(char *save);

int		get_next_line(int fd, char **line);
int		ft_strchr(char *s, char c);
int		ft_strlen(char *s);
int		ft_bzero(void *s);

char	*ft_strdup(char *s);
char	*newline(char *buffer);
char	*ft_strjoin(char *s1, char *s2);

#endif
