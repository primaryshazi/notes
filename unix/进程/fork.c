#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    __pid_t pid = fork();

    if (pid < 0)
    {
        printf("fork() error\n");
    }
    else if (0 == pid) // 子进程
    {
        printf("child[%d]\n", getpid());
    }
    else // 父进程
    {
        printf("father[%d]\n", getpid());
    }

    return 0;
}
