/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:30:23 by snarain           #+#    #+#             */
/*   Updated: 2021/11/15 17:15:51 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_path(t_struct *data)
{
	int		i;
	char	**tab;

	i = 0;
	while (ft_strnstr(data->env[i], "PATH", 4) == 0)
		i++;
	tab = ft_split(data->env[i] + 5, ':');
	return (tab);
}

void	exec_path(char *cmd, t_struct *data)
{
	int		i;
	char	**tab;
	char	*tmp;
	char	*path;

	tab = get_path(data);
	i = -1;
	while (tab[++i])
	{
		tmp = ft_strjoin(tab[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			data->ret = execve(path, data->cmd, data->env);
			if (data->ret == -1)
				perror("execve");
		}
		free(path);
	}
	ft_putstr_fd("command not found\n", 2);
	ft_exit(data, tab);
}
