/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:34:18 by snarain           #+#    #+#             */
/*   Updated: 2021/11/02 15:34:20 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct  s_struct
{
    pid_t   pid;
    int     pipefd[2];
    char    *path;
    int     lenarg;
    int     infile;
    int     outfile;
    char    **av;
    char    **env;
}   t_struct;

char        *get_path(char *cmd, t_struct *data);
void        ft_free_tab(char **tab);
int         get_len(char **av, char **path);
t_struct    init_data(int ac, char **av, char **env);
void        child_proc(t_struct *data, int i);
void        parent_proc(t_struct *data);
void        execute(char **cmd, t_struct *data);
#endif
