/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:48:19 by snarain           #+#    #+#             */
/*   Updated: 2021/11/10 15:48:24 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    execute(char *av, t_struct *data)
{
    char    **cmd;

    cmd = ft_split(av, ' ');
    data->path = get_path(cmd[0], data);
    if (data->path == NULL)
        perror("data->path");
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
    dup2(data->pipefd[0], STDIN_FILENO);
    dup2(tmp, STDOUT_FILENO);
    close(data->pipefd[1]);
    execute(data->av[3], data);
}
