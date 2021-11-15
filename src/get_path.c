/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:40:28 by snarain           #+#    #+#             */
/*   Updated: 2021/11/15 01:27:51 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **get_path(t_struct *data)
{
    int     i;
    char    **tab;

    i = 0;
    while (ft_strnstr(data->env[i], "PATH", 4) == 0)
        i++;
    tab = ft_split(data->env[i] + 5, ':');
    return (tab);
}

void    exec_path(char *cmd, t_struct *data)
{
    int     i;
    char    **tab;
    char    *tmp;
    char    *path;

    tab = get_path(data);
    i = -1;
    while (tab[++i])
    {
        tmp = ft_strjoin(tab[i], "/");
        path = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(path, F_OK) == 0)
            if (execve(path, data->cmd, data->env) == -1)
                {
                    ft_free_tab(tab);
                    free(path);
                    ft_free_tab(data->cmd);
                    perror("execve");
                    exit(1);
                }

    }
    ft_free_tab(tab);
    free(path);
    ft_free_tab(data->cmd);
    free(path);
    exit (1);
}
