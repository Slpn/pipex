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

void    execute(char *av, t_struct *data)
{
    char    **cmd;

    cmd = ft_split(av, ' ');
    data->path = get_path(cmd[0], data);
    // if (data->path == NULL)
    // {
    //     perror("data->path");
    //     // ft_free_tab(cmd);
    //     ft_exit(data);
    // }
    if (execve(data->path, cmd, data->env) == -1)
        perror("execve");
}

void    parent_proc(t_struct *data)
{
    int tmp;

    waitpid(data->pid,NULL, 0);
    tmp = open(data->av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (tmp == -1)
        perror("open");
    close(data->pipefd[1]);
    dup2(data->pipefd[0], STDIN_FILENO);
    dup2(tmp, STDOUT_FILENO);
    execute(data->av[3], data);
}

void    child_proc(t_struct *data)
{
    int tmp;

    tmp = open(data->av[1], O_RDONLY, 0777);
    if (tmp == -1)
       ft_exit(data);
    close(data->pipefd[0]);
    dup2(data->pipefd[1], 1);
    dup2(tmp, 0);
    execute(data->av[2], data);
}

int main(int ac, char **av, char **env)
{
    t_struct data;

    if (ac == 5)
    {
        data = init_data(ac, av, env);
        if (data.pid == 0)
            child_proc(&data);
        else
            parent_proc(&data);
        close(data.pipefd[0]);
        close(data.pipefd[1]);
    }
    else
        ft_putstr_fd("Error\n", 2);
    return (0);
}