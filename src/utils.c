#include "pipex.h"

void *init_data(char **av, char **env, t_struct *data)
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
    data->ret = 0;
    data->len = 0;
    data->path = get_path(env);
    data->pid = fork();
    data->av = av;
    data->env = env;
}

int    ft_tablen(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}
