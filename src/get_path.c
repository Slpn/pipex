/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:40:28 by snarain           #+#    #+#             */
/*   Updated: 2021/11/04 15:40:29 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **get_path(char **env)
{
    int     i;
    char    **tab;
    char    *tmp;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
            break ;
        i++;
    }
    tmp = ft_strdup(env[i]);
    tab = ft_split(tmp, ':');
    free(tmp);
    return (tab);
}
