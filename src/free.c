#include "pipex.h"

void ft_free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void ft_close(t_struct *data)
{
    int i;

    i = 0;
    while (i < data->lenarg)
    {
        close(data->pipefd[i]);
        i++;
    }
}
