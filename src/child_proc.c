#include "pipex.h"

void child_proc(t_struct *data)
{
    close(data->pipefd[0]);
    write(data->pipefd[1], data->av[1], ft_strlen(data->av[1]));
    close(data->pipefd[1]);
    return ;
}
