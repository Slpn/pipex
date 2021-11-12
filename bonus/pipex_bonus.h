/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:28:02 by snarain           #+#    #+#             */
/*   Updated: 2021/11/12 17:46:45 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
    char    buf[1024];
    char    *path;
    int     ret;
    int     lenarg;
    int     indexarg;
    char    **av;
    char    **env;
}   t_struct;

char    *get_path(char *cmd, t_struct *data);
void    ft_free_tab(char **tab);
int     get_len(char **av, char **path);
void    *init_data(int ac, char **av, char **env, t_struct *data);
void    child_proc(t_struct *data);
void    parent_proc(t_struct *data);
void    execute(char *av, t_struct *data);
void    ft_exit(t_struct *data);

#endif