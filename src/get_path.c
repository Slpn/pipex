/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:40:28 by snarain           #+#    #+#             */
/*   Updated: 2021/11/12 19:51:43 by snarain          ###   ########.fr       */
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
        // printf("env = %s\n", data->env);
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
    ft_putstr_fd("command not found\n", 2);
    return (NULL);
}