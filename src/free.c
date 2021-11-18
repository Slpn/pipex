/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:48:39 by snarain           #+#    #+#             */
/*   Updated: 2021/11/10 15:48:41 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(t_struct *data, char **cmd)
{
	ft_free_tab(cmd);
	ft_free_tab(data->cmd);
	exit (127);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_close(t_struct *data)
{
	close(data->infile);
	close(data->outfile);
}
