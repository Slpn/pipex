/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:31:56 by snarain           #+#    #+#             */
/*   Updated: 2021/11/26 16:02:26 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exit(t_struct *data, char **cmd)
{
	ft_free_tab(cmd);
	ft_free_tab(data->cmd);
	 
	if (data->index_main == data->lenarg - 2)
		exit (127);
	else 
		exit (0);
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
