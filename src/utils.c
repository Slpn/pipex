#include "pipex.h"

void *init_data(int ac, char **av, char **env, t_struct *data)
{
    if (pipe(data->pipefd)== -1)
    {
        perror("pipe");
        exit (1);
    }
    data->pid = fork();
    if (data->pid == -1)
    {
        perror("fork");
        exit (1);
    }
    // outfile = av[ac - 1]
    data->ret = 0;
    data->lenarg = ac - 3;
    data->av = av;
    data->path = get_path(env);
    data->env = env;
    data->pid = fork();
}

int    ft_tablen(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}
