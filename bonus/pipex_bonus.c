/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:27:02 by snarain           #+#    #+#             */
/*   Updated: 2021/11/15 19:44:03 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent_proc(t_struct *data)
{
	int	i;

	i = waitpid(-1, NULL, 0);
	if (i == -1)
	{
		perror("waitpid");
		exit(1);
	}
	close(data->pipefd[1]);
	close(data->infile);
	dup2(data->pipefd[0], data->infile);
	close(data->pipefd[0]);
}

void	child_proc(t_struct *data, int i)
{
	data->cmd = ft_split(data->av[i], ' ');
	dup2(data->infile, STDIN_FILENO);
	if (i == data->lenarg - 2)
		dup2(data->outfile, STDOUT_FILENO);
	else
		dup2(data->pipefd[1], STDOUT_FILENO);
	if (access(data->cmd[0], F_OK) == 0)
		execve(data->cmd[0], data->cmd, data->env);
	exec_path(data->cmd[0], data);
}

int	main(int ac, char **av, char **env)
{
	t_struct	data;
	int			i;

	i = 1;
	if (ac > 4)
	{
		if (ft_strnstr(av[1], "here_doc", 8) != 0)
			ft_heredoc(av, ac, env);
		else
		{
			data = init_data(ac, av, env);
			while (++i < data.lenarg - 1)
			{
				if (pipe(data.pipefd) == -1)
					perror("pipe");
				data.pid = fork();
				if (data.pid < 0)
					exit (1);
				else if (data.pid == 0)
					child_proc(&data, i);
				else
					parent_proc(&data);
			}
		}
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
