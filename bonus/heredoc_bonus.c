/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:19:49 by snarain           #+#    #+#             */
/*   Updated: 2021/11/15 19:40:02 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_struct	init_heredoc(int ac, char **av, char **env)
{
	t_struct	data;

	data.lenarg = ac;
	data.av = av;
	data.path = NULL;
	data.env = env;
	data.ret = 0;
	return (data);
}

void	ft_heredoc(char **av, int ac, char **env)
{
	t_struct	data;
	char		*line;
	int			tmp;

	tmp = ft_strleng(av[2]);
	line = NULL;
	data = init_heredoc(ac, av, env);
	while (1)
	{
		get_next_line(0, &line);
		if (ft_strnstr(line, data.av[2], tmp) != 0)
			break ;
	}
	return ;
}
