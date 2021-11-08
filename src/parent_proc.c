#include "pipex.h"

void   parent_proc(t_struct *data)
{
    close(data->pipefd[1]);
    wait(NULL);
    // while((ret = read(pipefd[0], &buf, 1023)))
    // {
    //     buf[ret] = 0;
    //     printf("%s\n", buf);
    // }
    data->path = get_path(data->env);
    if (execve(data->av[1], data->av + 1, data->env) == -1)
        perror("execve");
    close(data->pipefd[0]);
    ft_free_tab(data->path);
}
