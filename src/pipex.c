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

    if (ac > 4)
    {
        init_data(ac, av, env, &data);
        if (data.pid == 0)
            child_proc(&data);
        else
            parent_proc(&data);
        
    }
    return (0);
}
// int main(int ac, char **av, char **env)
// {
//     pid_t   pid;
//     int     *status;
//     int     x = 5;
//     pid = fork();
//     pid de lenfant == 0
//     pid du parent == son vrai pid
//     if (pid == -1)
//         perror("fork");
//     if (pid == 0)
//         {
//             x += 5;
//             printf("My pid  1 is: %d et %d\n", getpid(), x);
//             int pid2 = fork();
//             if (pid2 == 0)
//                 {
//                     x += 5;
//                     printf("My pid  3 is: %d et %d\n", getpid(), x);
//                     return(0);
//                 }
//             else if (pid2 > 0)
//                 {
//                     wait(NULL);
//                     printf("My pid  4 is: %d %d\n", getpid(), x);
//                 }
//
//                 return(0);
//
//         }
//     if (pid > 0)
//         {
//             wait(NULL);
//             printf("My pid  2 is: %d %d\n", getpid(), x);
//         }
//           printf("je suis le pid %d\n\n", getpid());
//
//     return (0);
// }
