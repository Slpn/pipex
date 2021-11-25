/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:27:02 by snarain           #+#    #+#             */
/*   Updated: 2021/11/25 18:55:34 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wait_loop(t_struct *data)
{
	int	status;

	while (data->lenarg - 1 > 2)
	{
		waitpid(0, &status, 0);
		data->lenarg--;
	}
}

void	parent_proc(t_struct *data)
{	
	close(data->pipefd[1]);
	close(data->infile);
	data->infile = data->pipefd[0];
}

void	child_proc(t_struct *data, int i)
{
	close(data->pipefd[0]);
	data->cmd = ft_split(data->av[i], ' ');
	data->ret = dup2(data->infile, STDIN_FILENO);
	if (data->ret == -1)
		perror("dup2");
	close(data->infile);
	if (i == data->lenarg - 2)
	{
		data->ret = dup2(data->outfile, STDOUT_FILENO);
		if (data->ret == -1)
			perror("dup2");
		close(data->outfile);
	}
	else
	{
		data->ret = dup2(data->pipefd[1], STDOUT_FILENO);
		if (data->ret == -1)
			perror("dup2");
	}
	close(data->pipefd[1]);
	if (access(data->cmd[0], F_OK) == 0)
		execve(data->cmd[0], data->cmd, data->env);
	exec_path(data->cmd[0], data);
	exit (127);
}

void	main_loops(t_struct *data)
{
	int	status;
	int	i;

	i = 0;
	while (++data->index_main < data->lenarg - 1)
	{
		if (pipe(data->pipefd) == -1)
			perror("pipe");
		data->pid = fork();
		if (data->pid < 0)
			exit (1);
		else if (data->pid == 0)
			child_proc(data, data->index_main);
		else
			parent_proc(data);
	}
	wait_loop(data);
	ft_close(data);
}

int	main(int ac, char **av, char **env)
{
	t_struct	data;

	if (ac > 4)
	{
		if (ft_strnstr(av[1], "here_doc", 8) != 0)
			ft_heredoc(av, ac, env);
		else
		{
			data = init_data(ac, av, env);
			main_loops(&data);
		}
	}
	else
		exit (1);
	return (0);
}
