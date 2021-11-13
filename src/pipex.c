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

# include "pipex.h"

void    execute(char **cmd, t_struct *data)
{

    data->path = get_path(cmd[0], data);
    if (data->path == NULL)
    {
        perror("data->path");
        exit(1);
    }
    if (execve(data->path, cmd, data->env) == -1)
        perror("execve");
    return ;
}

void    parent_proc(t_struct *data)
{
	waitpid(-1, NULL, 0);
	close(data->pipefd[1]);
	close(data->infile);
	dup2(data->pipefd[0], data->infile);
	close(data->pipefd[0]);
}

void    child_proc(t_struct *data, int i)
{
    char    **cmd;

    cmd = ft_split(data->av[i], ' ');
	dup2(data->infile, STDIN_FILENO);
	if (i == data->lenarg - 2)
		dup2(data->outfile, STDOUT_FILENO);
	else
		dup2(data->pipefd[1], STDOUT_FILENO);
    execute(cmd, data);
}

int main(int ac, char **av, char **env)
{
    t_struct data;
    int     i;

    i = 1;
    if (ac == 5)
    {
        data = init_data(ac, av, env);
        while (++i < data.lenarg - 1)
        {
            if (pipe(data.pipefd)== -1)
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
    else
        ft_putstr_fd("Error\n", 2);
    return (0);
}