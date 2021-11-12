/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:49:24 by snarain           #+#    #+#             */
/*   Updated: 2021/11/10 15:49:25 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_struct init_data(int ac, char **av, char **env)
{
    t_struct data;

    if (pipe(data.pipefd)== -1)
    {
        perror("pipe");
        // exit(1);
    }
    data.pid = fork();
    if (data.pid == -1)
    {
        perror("fork");
        // ft_exit(data);
    }
    data.ret = 0;
    data.lenarg = ac - 3;
    data.av = av;
    data.path = NULL;
    data.env = env;
    return (data);
}

int    ft_tablen(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}
