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
    pid_t pid;
    int pipefd[2];
    char buf[1024];
    int ret = 0;

    if (pipe(pipefd))
    {
        perror("pipe");
        return 1;
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    if (pid == 0)
    {
        close(pipefd[0]);
        write(pipefd[1], av[1], ft_strlen(av[1]));
        close(pipefd[1]);
        return (0);
    }
    else
    {
        close(pipefd[1]);
        while((ret = read(pipefd[0], &buf, 1023)))
        {
          buf[ret] = 0;
          printf("%s\n", buf);
        }
        close(pipefd[0]);
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
// if (ac > 1)
// {
//     if (execve(av[1], (av + 1), env) == -1)
//         perror("execve");
//     else
//     {
//         while ()
//             wait(&status);
//     }
// }
