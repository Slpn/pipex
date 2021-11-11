/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:40:28 by snarain           #+#    #+#             */
/*   Updated: 2021/11/12 00:51:14 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *get_path(char *cmd, t_struct *data)
{
    int     i;
    char    **tab;
    char    *tmp;
    char    *path;

    i = 0;
    while (data->env[i])
    {
        if (ft_strncmp(data->env[i], "PATH=", 5) == 0)
            break ;
        i++;
    }
    tab = ft_split(data->env[i] + 5, ':');
    i = 0;
    while (tab[i])
    {
        tmp = ft_strjoin(tab[i], "/");
        path = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(path, F_OK) == 0)
            return(path);
        i++;
    }
    ft_putstr_fd("command not found", 2);
    return (NULL);
}
