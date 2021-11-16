/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:19:49 by snarain           #+#    #+#             */
/*   Updated: 2021/11/16 19:56:29 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_struct	init_heredoc(int ac, char **av, char **env)
{
	t_struct	data;

	data.lenarg = ac;
	data.av = av;
	data.path = NULL;
	data.env = env;
	data.ret = 0;
	data.line = NULL;
	return (data);
}

void	exec_heredoc(t_struct *data)
{
	if (pipe(data->pipefd) == -1)
		perror("pipe");
	
}

void	ft_heredoc(char **av, int ac, char **env)
{
	t_struct	data;
	char		*line;
	int			len;

	len = ft_strleng(av[2]);
	line = NULL;
	data = init_heredoc(ac, av, env);
	while (get_next_line(0, &line) != 0)
	{
		if (ft_strnstr(line, data.av[2], len) != 0)
			break ;
		data.line = ft_strjoing(data.line, line);
		free(line);
	}
	if (line)
		free(line);
	exec_heredoc(&data);
	return ;
}
