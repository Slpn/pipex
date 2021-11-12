/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:27:02 by snarain           #+#    #+#             */
/*   Updated: 2021/11/12 17:54:44 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void    execute(char *av, t_struct *data)
{
    char    **cmd;

    cmd = ft_split(av, ' ');
    data->path = get_path(cmd[0], data);
    if (data->path == NULL)
    {
        perror("data->path");
        // ft_free_tab(cmd);
        ft_exit(data);
    }
    if (execve(data->path, cmd, data->env) == -1)
        perror("execve");
}

void    parent_proc(t_struct *data)
{
    int tmp;

    waitpid(data->pid,NULL, 0);
    data->indexarg++;
    tmp = open(data->av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (tmp == -1)
        perror("open");
    dup2(data->pipefd[0], STDIN_FILENO);
    dup2(tmp, STDOUT_FILENO);
    close(data->pipefd[1]);
    execute(data->av[data->indexarg], data);
}

void    child_proc(t_struct *data)
{
    int tmp;

    tmp = open(data->av[1], O_RDONLY, 0777);
    if (tmp == -1)
       ft_exit(data);
    data->indexarg++;
    dup2(data->pipefd[1], STDOUT_FILENO);
    dup2(tmp, STDIN_FILENO);
    close(data->pipefd[0]);
    execute(data->av[data->indexarg], data);
}

int main(int ac, char **av, char **env)
{
    t_struct    data;
    int         i;

    i = 0;
    if (ac > 4)
    {
        init_data(ac, av, env, &data);
        while (++i < data.lenarg)
        {
            data.pid = fork();
            if (data.pid == -1)
                perror("pid");
            if (data.pid == 0)
                child_proc(&data);
            else
                parent_proc(&data);
        }
        close(data.pipefd[0]);
        close(data.pipefd[1]);
    }
    else
        ft_putstr_fd("Error\n", 2);
    return (0);
}