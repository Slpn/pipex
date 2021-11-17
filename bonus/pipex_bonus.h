/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:28:02 by snarain           #+#    #+#             */
/*   Updated: 2021/11/17 18:25:17 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../GNL/get_next_line.h"

typedef struct s_struct
{
	pid_t	pid;
	int		pipefd[2];
	char	*path;
	int		lenarg;
	int		infile;
	int		outfile;
	int		ret;
	char	*line;
	char	**cmd;
	char	**av;
	char	**env;
	int		index_main;
}	t_struct;

void		ft_free_tab(char **tab);
int			get_len(char **av, char **path);
t_struct	init_data(int ac, char **av, char **env);
void		child_proc(t_struct *data, int i);
void		parent_proc(t_struct *data);
char		**get_path(t_struct *data);
void		exec_path(char *cmd, t_struct *data);
void		ft_exit(t_struct *data, char **cmd);
void		ft_heredoc(char **av, int ac, char **env);
char		*ft_strjoin_h(char *s1, char *s2);
void		main_loops(t_struct *data);

#endif
