#include "pipex.h"

int get_len(char **av, char **path)
{
    int i;
    int j;
    int count;
    int flag;

    j = 0;
    i = 2;
    count = 0;
    flag = 0;
    while (av[i + 1])
    {
        j = 0;
        while (path[j])
        {
            if (access(path[j], flag))
                break ;
            printf("flag = %d\n", flag);
            j++;
        }
        i++;
        count++;
    }
    return (count);
}
