/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:19:49 by snarain           #+#    #+#             */
/*   Updated: 2021/11/25 00:19:11 by snarain          ###   ########.fr       */
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

void	heredoc_parent(t_struct *data)
{
	waitpid(data->pid, NULL, 0);
	dup2(data->pipefd[0], data->infile);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	main_loops(data);
	close(data->outfile);
}

void	ft_heredoc(char **av, int ac, char **env)
{
	t_struct	data;

	data = init_heredoc(ac, av, env);
	if (pipe(data.pipefd) == -1)
		perror("pipe");
	data.pid = fork();
	if (data.pid > 0)
		heredoc_parent(&data);
	dup2(data.pipefd[1], STDOUT_FILENO);
	while (get_next_line(0, &data.line) != 0)
	{
		if (ft_strnstr(data.line, av[2], ft_strlen(av[2])) != 0)
			break ;
		write(data.pipefd[1], data.line, ft_strleng(data.line));
		write(data.pipefd[1], "\n", 1);
		free(data.line);
	}
	if (data.line)
		free(data.line);
	return ;
}
