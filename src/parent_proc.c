#include "pipex.h"

void   parent_proc(t_struct *data)
{
    close(data->pipefd[1]);
    wait(NULL);
    if (execve(data->av[1], data->av, "/bin/ls") == -1)
    {
        perror("execve");
        exit(1);
    }
    close(data->pipefd[0]);
}
