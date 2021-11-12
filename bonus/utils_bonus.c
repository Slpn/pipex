/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:29:46 by snarain           #+#    #+#             */
/*   Updated: 2021/11/12 17:47:58 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void *init_data(int ac, char **av, char **env, t_struct *data)
{
    if (pipe(data->pipefd)== -1)
    {
        perror("pipe");
        // exit(1);
    }
    data->ret = 0;
    data->lenarg = ac - 3;
    data->av = av;
    data->path = NULL;
    data->env = env;
    data->indexarg = 1;
}

int    ft_tablen(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}