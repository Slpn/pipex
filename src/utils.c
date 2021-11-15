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

t_struct	init_data(int ac, char **av, char **env)
{
	t_struct	data;

	data.infile = open(av[1], O_RDONLY);
	if (data.infile == -1)
	{
		perror(av[1]);
		exit (1);
	}
	data.outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data.outfile == -1)
	{
		perror(av[ac - 1]);
		close(data.infile);
		exit (1);
	}
	data.lenarg = ac;
	data.av = av;
	data.path = NULL;
	data.env = env;
	data.ret = 0;
	return (data);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
