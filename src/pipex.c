/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:34:12 by snarain           #+#    #+#             */
/*   Updated: 2021/11/02 15:34:14 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_proc(t_struct *data)
{
	int	i;
	int	status;

	i = waitpid(data->pid, &status, 0);
	if (i == -1)
	{
		perror("waitpid");
		exit(1);
	}
	close(data->pipefd[1]);
	close(data->infile);
	dup2(data->pipefd[0], data->infile);
	close(data->pipefd[0]);
	if (status == 32512 && data->index_main == data->lenarg - 2)
		exit (127);
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

	if (ac == 5)
	{
		data = init_data(ac, av, env);
		while (++data.index_main < data.lenarg - 1)
		{
			if (pipe(data.pipefd) == -1)
				perror("pipe");
			data.pid = fork();
			if (data.pid < 0)
				exit (1);
			else if (data.pid == 0)
				child_proc(&data, data.index_main);
			else
				parent_proc(&data);
		}
		ft_close(&data);
	}
	else
		exit(1);
	return (0);
}
