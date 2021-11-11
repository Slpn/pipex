/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:34:12 by snarain           #+#    #+#             */
/*   Updated: 2021/11/02 15:34:14 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int main(int ac, char **av, char **env)
{
    t_struct data;

    if (ac == 5)
    {
        init_data(ac, av, env, &data);
        if (data.pid == 0)
            child_proc(&data);
        else
            parent_proc(&data);
        close(data.pipefd[0]);
        close(data.pipefd[1]);
    }
    else
        ft_putstr_fd("Error\n", 2);
    return (0);
}