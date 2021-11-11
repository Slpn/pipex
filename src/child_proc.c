/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:50:23 by snarain           #+#    #+#             */
/*   Updated: 2021/11/12 00:50:23 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    child_proc(t_struct *data)
{
    int tmp;

    tmp = open(data->av[1], O_RDONLY, 0777);
    if (tmp == -1)
        exit(1);
    dup2(data->pipefd[1], STDOUT_FILENO);
    dup2(tmp, STDIN_FILENO);
    close(data->pipefd[0]);
    execute(data->av[2], data);
    return ;
}
