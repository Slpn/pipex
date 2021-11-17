/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:19:49 by snarain           #+#    #+#             */
/*   Updated: 2021/11/17 17:40:45 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_struct	init_heredoc(int ac, char **av, char **env)
{
	t_struct	data;

	data.outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data.outfile == -1)
	{
		perror(av[ac - 1]);
		exit (1);
	}
	data.lenarg = ac;
	data.av = av;
	data.path = NULL;
	data.env = env;
	data.ret = 0;
	data.line = NULL;
	data.infile = 0;
	data.index_main = 2;
	return (data);
}

void	ft_heredoc(char **av, int ac, char **env)
{
	t_struct	data;
	char		*line;
	int			len;

	len = ft_strleng(av[2]);
	line = NULL;
	data = init_heredoc(ac, av, env);
	if (pipe(data.pipefd) == -1)
		perror("pipe");
	dup2(data.pipefd[1], STDOUT_FILENO);
	while (get_next_line(0, &line) != 0)
	{
		if (ft_strnstr(line, data.av[2], len) != 0)
			break ;
		write(data.pipefd[1], line, ft_strleng(line));
		write(data.pipefd[1], "\n", 1);
		free(line);
	}
	if (line)
		free(line);
	main_loops(&data);
	return ;
}
